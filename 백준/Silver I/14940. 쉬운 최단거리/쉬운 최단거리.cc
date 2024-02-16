#include <iostream>
#include <queue>
using namespace std;

int N, M, StartY, StartX;
vector<vector<int>> Board;
vector<vector<int>> Cost;
queue<pair<int, int>> Queue;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void BFS()
{
	Queue.push({ StartY, StartX });
	Cost[StartY][StartX] = 0;

	while (Queue.empty() == false)
	{
		pair<int, int> Current = Queue.front(); Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= M) continue;
			if (Cost[NextY][NextX] != -1 && Cost[NextY][NextX] <= Cost[Current.first][Current.second] + 1) continue;

			Cost[NextY][NextX] = Cost[Current.first][Current.second] + 1;
			Queue.push({ NextY, NextX });
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Board = vector<vector<int>>(N, vector<int>(M, 0));
	Cost = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Board[i][j];
			if (Board[i][j] == 2)
			{
				StartY = i;
				StartX = j;
			}
			else if (Board[i][j] == 0)
			{
				Cost[i][j] = 0;
			}
		}
	}

	BFS();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << Cost[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}