#include <iostream>
#include <vector>
using namespace std;

int R, C, N, Time;
vector<vector<char>> Board;
vector<pair<int, int>> CurrentBombPos;
vector<vector<pair<int, int>>> BombPos;
int dY[4] = { 0, 0, -1, 1 };
int dX[4] = { -1, 1, 0, 0 };

void PlantBomb()
{
    CurrentBombPos.clear();
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (Board[i][j] == '.')
            {
                Board[i][j] = 'O';
                CurrentBombPos.push_back({ i, j });
            }
        }
    }

    BombPos.push_back(CurrentBombPos);
}

bool CheckIsRemain(pair<int,int> CurrentPos)
{
    //Time - 5 의 BombPos 에 영향을 받는지 확인
    int CheckTime = Time - 5;
    for (int i = 0; i < BombPos[CheckTime].size(); ++i)
    {
        int CurrentBombY = BombPos[CheckTime][i].first;
        int CurrentBombX = BombPos[CheckTime][i].second;

        if (CurrentPos.first == CurrentBombY && CurrentPos.second == CurrentBombX) return false;

        for (int j = 0; j < 4; ++j)
        {
            int NextBombY = CurrentBombY + dY[j];
            int NextBombX = CurrentBombX + dX[j];

            if (NextBombY < 0 || NextBombY >= R || NextBombX < 0 || NextBombX >= C) continue;
            if (CurrentPos.first == NextBombY && CurrentPos.second == NextBombX) return false;
        }
    }

    return true;
}

void Boom()
{
    // 현재 시간 대비 3초 전
    int InTime = Time - 3;
    for (int i = 0; i < BombPos[InTime].size(); ++i)
    {
        if (InTime > 0 && CheckIsRemain(BombPos[InTime][i]) == false)
        {
            continue;
        }

        Board[BombPos[InTime][i].first][BombPos[InTime][i].second] = '.';

        for (int j = 0; j < 4; ++j)
        {
            int NextY = BombPos[InTime][i].first + dY[j];
            int NextX = BombPos[InTime][i].second + dX[j];

            if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;

            Board[NextY][NextX] = '.';
        }
    }
}

void PrintBoard()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << Board[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C >> N;

    Board = vector<vector<char>>(R, vector<char>(C));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Board[i][j];
            if (Board[i][j] == 'O')
            {
                CurrentBombPos.push_back({ i, j });
            }
        }
    }

    BombPos.push_back(CurrentBombPos);

    // 1초
    Time = 1;
    BombPos.push_back(vector<pair<int, int>>());
    // 아무것도 하지 않음
    if (N == Time)
    {
        PrintBoard();
        return 0;
    }

    N %= 4;

    // 2초
    Time++;
    // 빈 곳에 폭탄을 설치
    PlantBomb();
    if (N == 2)
    {
        PrintBoard();
        return 0;
    }

    // 3초
    Time++;
    Boom();
    if (N == 3)
    {
        PrintBoard();
        return 0;
    }

    // 4초
    Time++;
    PlantBomb();
    if (N == 0)
    {
        PrintBoard();
        return 0;
    }

    // 5초, N==1
    Time++;
    Boom();
    PrintBoard();

    return 0;
}