#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;

vector<vector<int>> Board;
vector<vector<bool>> Visited;

int dx[2] = { 0, 1 };
int dy[2] = { 1, 0 };

void BFS(int X, int Y)
{
    queue<pair<int, int>> Queue;

    Queue.push({ X, Y });

    while (Queue.empty() == false)
    {
        pair<int, int> Current = Queue.front(); Queue.pop();
        if (Visited[Current.first][Current.second]) continue;
        Visited[Current.first][Current.second] = true;

        for (int i = 0; i < 2; ++i)
        {
            int NextX = Current.first + dx[i];
            int NextY = Current.second + dy[i];

            if (NextX > N || NextY > M) continue;

            Board[NextX][NextY] += Board[Current.first][Current.second];
            Queue.push({ NextX, NextY });
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    Board = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    Visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));

    Board[1][1] = 1;

    BFS(1, 1);

    if (K != 0)
    {
        // 8 / 5 = 1
        int X = (K / M) + 1;
        // 8 % 5 = 3
        int Y = K % M;

        int Count = Board[X][Y];
        Board = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
        Visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
        Board[X][Y] = Count;
        BFS(X, Y);
    }

    cout << Board[N][M] << '\n';

    return 0;
}