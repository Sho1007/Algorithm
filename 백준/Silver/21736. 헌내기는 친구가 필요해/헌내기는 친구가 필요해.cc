#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string> Map;
vector<vector<bool>> Visited;
pair<int, int> PlayerPos = { -1, -1 };
int N, M, Answer = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


void BFS()
{
    queue<pair<int, int>> Queue;

    Queue.push(PlayerPos);
    Visited[PlayerPos.first][PlayerPos.second] = true;

    while (Queue.empty() == false)
    {
        pair<int, int> CurrentPos = Queue.front(); Queue.pop();

        if (Map[CurrentPos.first][CurrentPos.second] == 'P')
        {
            Answer++;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextY = CurrentPos.first + dy[i];
            int NextX = CurrentPos.second + dx[i];

            if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= M) continue;
            if (Visited[NextY][NextX] || Map[NextY][NextX] == 'X') continue;
            Visited[NextY][NextX] = true;
            Queue.push({ NextY, NextX });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    Map = vector<string>(N);
    Visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
    {
        cin >> Map[i];
        if (PlayerPos.first != -1)
        {
            continue;
        }

        for (int j = 0; j < M; ++j)
        {
            if (Map[i][j] == 'I')
            {
                PlayerPos = { i, j };
                break;
            }
        }
    }

    BFS();

    if (Answer == 0)
    {
        cout << "TT\n";
    }
    else
    {
        cout << Answer << '\n';
    }

    return 0;
}