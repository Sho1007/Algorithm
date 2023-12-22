#include <iostream>
#include <queue>
using namespace std;

int R, C;

vector<vector<int>> CostVector;
vector<string> Board;

pair<int, int> StartPos;

queue<pair<int, int>> PlayerPosQueue;
queue<pair<int, int>> FirePosQueue;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void Print()
{
	cout << '\n';

	for (int i = 0; i < R; ++i)
	{
		cout << Board[i] << '\n';
	}

	cout << '\n';

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << CostVector[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;

	Board = vector<string>(R);
	CostVector = vector<vector<int>>(R, vector<int>(C, 987'654'321));

	for (int i = 0; i < R; ++i)
	{
		cin >> Board[i];

		for (int j = 0; j < C; ++j)
		{
			if (Board[i][j] == 'J')
			{
				StartPos = { i, j };
			}
			if (Board[i][j] == 'F')
			{
				FirePosQueue.push({ i, j });
			}
		}
	}

	CostVector[StartPos.first][StartPos.second] = 0;

	PlayerPosQueue.push(StartPos);


	

	while (PlayerPosQueue.empty() == false)
	{
		queue<pair<int, int>> NewFirePosQueue;
		while (FirePosQueue.empty() == false)
		{
			pair<int, int> Current = FirePosQueue.front(); FirePosQueue.pop();

			for (int i = 0; i < 4; ++i)
			{
				int NextY = Current.first + dy[i];
				int NextX = Current.second + dx[i];

				if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
				if (Board[NextY][NextX] == 'F' || Board[NextY][NextX] == '#') continue;

				Board[NextY][NextX] = 'F';
				NewFirePosQueue.push({ NextY, NextX });
			}
		}

		FirePosQueue = NewFirePosQueue;


		queue<pair<int, int>> NewPlayerPosQueue;
		while (PlayerPosQueue.empty() == false)
		{
			pair<int, int> Current = PlayerPosQueue.front(); PlayerPosQueue.pop();

			for (int i = 0; i < 4; ++i)
			{
				int NextY = Current.first + dy[i];
				int NextX = Current.second + dx[i];

				if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
				if (Board[NextY][NextX] == 'F' || Board[NextY][NextX] == '#') continue;
				if (CostVector[NextY][NextX] <= CostVector[Current.first][Current.second] + 1) continue;

				CostVector[NextY][NextX] = CostVector[Current.first][Current.second] + 1;
				NewPlayerPosQueue.push({ NextY, NextX });
			}
		}

		PlayerPosQueue = NewPlayerPosQueue;

		// Print();
	}

	int MinNum = 987'654'321;

	for (int i = 0; i < R; ++i)
	{
		if (MinNum > CostVector[i][0]) MinNum = CostVector[i][0];
		if (MinNum > CostVector[i][C - 1]) MinNum = CostVector[i][C - 1];
	}

	for (int i = 0; i < C; ++i)
	{
		if (MinNum > CostVector[0][i]) MinNum = CostVector[0][i];
		if (MinNum > CostVector[R - 1][i]) MinNum = CostVector[R - 1][i];
	}

	if (MinNum == 987'654'321)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << MinNum + 1 << '\n';
	}

	return 0;
}