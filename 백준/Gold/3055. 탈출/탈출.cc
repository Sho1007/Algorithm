#include <iostream>
#include <queue>
#define MAX 987'654'321
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int R, C, StartY, StartX, EndY, EndX;

vector<vector<char>> Board;
vector<vector<int>> Cost;

queue < pair<int, int> > WaterQueue;
queue < pair<int, int> > MoveQueue;

void Print()
{
	cout << "Board : \n";
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << Board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "Cost : \n";
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << Cost[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool BFS()
{
	queue < pair<int, int> > NewWaterQueue;

	while (WaterQueue.empty() == false)
	{
		pair<int, int> Current = WaterQueue.front(); WaterQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
			if (Board[NextY][NextX] != '.' && Board[NextY][NextX] != 'S') continue;

			Board[NextY][NextX] = '*';
			NewWaterQueue.push({ NextY, NextX });
		}
	}

	WaterQueue = NewWaterQueue;

	queue < pair<int, int> > NewMoveQueue;

	while (MoveQueue.empty() == false)
	{
		pair<int, int> Current = MoveQueue.front();
		MoveQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C) continue;
			if (Board[NextY][NextX] == '*' || Board[NextY][NextX] == 'X') continue;
			if (Cost[NextY][NextX] > Cost[Current.first][Current.second] + 1)
			{
				Cost[NextY][NextX] = Cost[Current.first][Current.second] + 1;
				if (Board[NextY][NextX] == '.') NewMoveQueue.push({NextY, NextX});
			}
		}
	}

	if (NewMoveQueue.size() == 0) return false;

	MoveQueue = NewMoveQueue;
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;

	Board = vector<vector<char>>(R, vector<char>(C));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> Board[i][j];

			if (Board[i][j] == 'S')
			{
				StartY = i;
				StartX = j;
			}
			else if (Board[i][j] == 'D')
			{
				EndY = i;
				EndX = j;
			}
			else if (Board[i][j] == '*')
			{
				WaterQueue.push({ i,j });
			}
		}
	}

	Cost = vector<vector<int>>(R, vector<int>(C, MAX));

	Cost[StartY][StartX] = 0;
	MoveQueue.push({ StartY, StartX });

	//Print();

	while (BFS())
	{
		//Print();
	}

	if (Cost[EndY][EndX] == MAX)
	{
		cout << "KAKTUS\n";
	}
	else
	{
		cout << Cost[EndY][EndX] << '\n';
	}

	return 0;
}