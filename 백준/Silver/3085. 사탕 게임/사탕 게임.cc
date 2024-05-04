#include <iostream>
#include <string>
using namespace std;

inline int MAX(int A, int B) { return A > B ? A : B; }

int N, Answer = 0;

string Board[50] = {};

bool IsVisited[50][50] = {};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void SwapColor(int fromX, int fromY, int toX, int toY)
{
    char Temp = Board[fromX][fromY];
    Board[fromX][fromY] = Board[toX][toY];
    Board[toX][toY] = Temp;
}
int CheckLength(int X, int Y)
{
    int Count[4] = {};

    for (int i = 0; i < 4; ++i)
    {
        int NextX = X;
        int NextY = Y;

        while (0 <= NextX && NextX < N && 0 <= NextY && NextY < N)
        {
            if (Board[NextX][NextY] == Board[X][Y])
            {
                Count[i]++;

                NextX += dx[i];
                NextY += dy[i];
            }
            else
            {
                break;
            }
        }
    }
    
    return MAX(Count[0] + Count[1], Count[2] + Count[3]) - 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Board[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Answer = MAX(Answer, CheckLength(i, j));
            
            if (i < N - 1 && Board[i][j] != Board[i+1][j])
            {
                SwapColor(i, j, i + 1, j);

                Answer = MAX(Answer, CheckLength(i, j));
                Answer = MAX(Answer, CheckLength(i + 1, j));

                SwapColor(i, j, i + 1, j);
            }

            if (j < N - 1 && Board[i][j] != Board[i][j+1])
            {
                SwapColor(i, j, i, j+1);

                Answer = MAX(Answer, CheckLength(i, j));
                Answer = MAX(Answer, CheckLength(i, j+1));

                SwapColor(i, j, i, j+1);
            }
        }
    }

    cout << Answer << '\n';
    
    return 0;
}