#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
char Input;
vector<vector<int>> Board;
vector<pair<int, int>> BombPos;
int dY[4] = { 0, 0, -1, 1 };
int dX[4] = { -1, 1, 0, 0 };

void PlantBomb()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (Board[i][j] == 0)
            {
                Board[i][j] = 3;
            }
        }
    }
}

void SpendTime()
{
    BombPos.clear();

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (Board[i][j] == 0) continue;

            if (--Board[i][j] == 0)
            {
                BombPos.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < BombPos.size(); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int NextY = BombPos[i].first + dY[j];
            int NextX = BombPos[i].second + dX[j];

            if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
            Board[NextY][NextX] = 0;
        }
    }
}

void PrintBoard()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << (Board[i][j] == 0 ? '.' : 'O');
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C >> N;

    Board = vector<vector<int>>(R, vector<int>(C, 0));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Input;
            Board[i][j] = (Input == 'O' ? 3 : 0);
        }
    }

    SpendTime();
    if (N == 1)
    {
        PrintBoard();
        return 0;
    }

    N %= 4;

    SpendTime();
    PlantBomb();
    if (N == 2)
    {
        PrintBoard();
        return 0;
    }

    SpendTime();
    if (N == 3)
    {
        PrintBoard();
        return 0;
    }

    SpendTime();
    PlantBomb();
    if (N == 0)
    {
        PrintBoard();
        return 0;
    }

    SpendTime();
    PrintBoard();

    return 0;
}