#include <iostream>
#include <queue>
using namespace std;

int N, M, K, Y, X, MaxResult = 0;

vector<vector<char>> Board;
vector<vector<bool>> Visit;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void BFS()
{
	int Result = 0;
	queue<pair<int, int>> Queue;

	Queue.push({ Y, X });
	Visit[Y][X] = true;
	Result++;

	while (Queue.empty() == false)
	{
		pair<int, int> Current = Queue.front(); Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY <= 0 || NextY > N || NextX <= 0 || NextX > M) continue;
			if (Board[NextY][NextX] != '#' || Visit[NextY][NextX] == true) continue;

			Queue.push({ NextY, NextX });
			Visit[NextY][NextX] = true;
			Result++;
		}
	}

	if (MaxResult < Result) MaxResult = Result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	Board = vector<vector<char>>(N + 1, vector<char>(M + 1, '.'));
	Visit = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));

	for (int i = 0; i < K; ++i)
	{
		cin >> Y >> X;
		Board[Y][X] = '#';
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (Visit[i][j] == false && Board[i][j] == '#')
			{
				Y = i; X = j;
				BFS();
			}
		}
	}

	cout << MaxResult << '\n';

	return 0;
}