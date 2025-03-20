#include <iostream>
#include <vector>
#define INF 987'654'321
using namespace std;

int R, C, K;
vector<vector<char>> Board;
vector<vector<int>> Cost;
int Answer = 0;

int dY[4] = { 0, 0, -1, 1 };
int dX[4] = { -1, 1, 0, 0 };

void PrintBoard()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << (Cost[i][j] == INF ? 0 : Cost[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';
}

void DFS(int Y, int X)
{
    if (Y == 0 && X == C - 1 && Cost[Y][X] == K - 1)
    {
        // PrintBoard();
        Answer++;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int NextY = Y + dY[i];
        int NextX = X + dX[i];

        if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
        if (Board[NextY][NextX] != '.' || Cost[NextY][NextX] != INF) continue;

        Cost[NextY][NextX] = Cost[Y][X] + 1;
        DFS(NextY, NextX);
        Cost[NextY][NextX] = INF;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> K;

    Board = vector<vector<char>>(R, vector<char>(C));
    Cost = vector<vector<int>>(R, vector<int>(C, INF));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Board[i][j];
        }
    }

    Cost[R-1][0] = 0;
    DFS(R-1, 0);

    cout << Answer << '\n';

    return 0;
}