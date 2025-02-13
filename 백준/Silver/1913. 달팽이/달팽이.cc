#include <iostream>
#include <vector>
using namespace std;

int N, FindTarget, TargetX, TargetY;
vector<vector<int>> Board;

int DirX[4] = { 1, 0, -1, 0 };
int DirY[4] = { 0, 1, 0, -1 };

int Num;
int CurX = 0;
int CurY = 0;
int CurDir = 0;
int NextX, NextY;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> FindTarget;

    Board = vector<vector<int>>(N, vector<int>(N, 0));

    Num = N * N;

    Board[0][0] = Num;

    while (--Num > 0)
    {
        NextX = CurX + DirX[CurDir];
        NextY = CurY + DirY[CurDir];

        if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N)
        {
            CurDir = (CurDir + 1) % 4;
            Num++;
            continue;
        }
        if (Board[NextX][NextY] != 0)
        {
            CurDir = (CurDir + 1) % 4;
            Num++;
            continue;
        }

        CurX = NextX;
        CurY = NextY;

        Board[CurX][CurY] = Num;
        if (Num == FindTarget)
        {
            TargetX = CurX;
            TargetY = CurY;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << Board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << TargetX + 1 << ' ' << TargetY + 1  << '\n';

    return 0;
}