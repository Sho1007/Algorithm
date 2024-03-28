#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
vector<string> Board;
vector<vector<bool>> Visit;

int WhitePower = 0;
int BluePower = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int Y, int X)
{
	queue<pair<int, int>> Queue;

	Queue.push({ Y, X });

	Visit[Y][X] = true;

	int TotalCount = 1;

	while (Queue.empty() == false)
	{
		auto Current = Queue.front(); Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= M) continue;
			if (Visit[NextY][NextX] == true || Board[NextY][NextX] != Board[Y][X]) continue;

			Visit[NextY][NextX] = true;
			TotalCount++;

			Queue.push({ NextY, NextX });
		}
	}

	if (Board[Y][X] == 'W')
	{
		WhitePower += TotalCount * TotalCount;
	}
	else
	{
		BluePower += TotalCount * TotalCount;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M >> N;

	Board = vector<string>(N);
	Visit = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
	{
		cin >> Board[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (false == Visit[i][j])
			{
				BFS(i, j);
			}
		}
	}

	cout << WhitePower << ' ' << BluePower << '\n';

	return 0;
}