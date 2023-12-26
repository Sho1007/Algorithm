#include <iostream>
#include <queue>
using namespace std;

int N;

int ProblemNum = 1;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

vector<vector<int>> Board;
vector<vector<int>> Cost;
queue<pair<int, int>> Queue;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> N;

		if (N == 0) break;

		Board.clear();
		Cost.clear();

		Board = vector<vector<int>>(N, vector<int>(N));
		Cost = vector<vector<int>>(N, vector<int>(N, 987'654'321));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> Board[i][j];
			}
		}

		Cost[0][0] = Board[0][0];

		Queue.push({ 0,0 });

		while (Queue.empty() == false)
		{
			pair<int, int> Current = Queue.front(); Queue.pop();

			for (int i = 0; i < 4; ++i)
			{
				int NextY = Current.first + dy[i];
				int NextX = Current.second + dx[i];

				if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;
				if (Cost[NextY][NextX] <= Cost[Current.first][Current.second] + Board[NextY][NextX]) continue;

				Cost[NextY][NextX] = Cost[Current.first][Current.second] + Board[NextY][NextX];
				Queue.push({ NextY, NextX });
			}
		}

		cout << "Problem " << ProblemNum++ << ": " << Cost[N - 1][N - 1] << '\n';
	}

	return 0;
}