#include <iostream>
#include <string>
#include <queue>
using namespace std;

int R, C;
vector<string> Board;
vector<vector<bool>> Visit;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int VCount = 0;
int OCount = 0;

void BFS(int Y, int X)
{
	queue<pair<int, int>> Queue;
	Queue.push({ Y, X });

	bool bIsOut = false;
	int CurrentV = 0;
	int CurrentO = 0;

	Visit[Y][X] = true;
	if (Board[Y][X] == 'o')
	{
		CurrentO++;
	}
	else if (Board[Y][X] == 'v')
	{
		CurrentV++;
	}

	while (Queue.empty() == false)
	{
		pair<int,int> Current = Queue.front(); Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= R || NextX < 0 || NextX >= C)
			{
				bIsOut = true;
				continue;
			}
			if (Visit[NextY][NextX] == true || Board[NextY][NextX] == '#') continue;
			if (Board[NextY][NextX] == 'o')
			{
				CurrentO++;
			}
			else if (Board[NextY][NextX] == 'v')
			{
				CurrentV++;
			}

			Visit[NextY][NextX] = true;

			Queue.push({ NextY, NextX });
		}
	}

	if (bIsOut == false)
	{
		if (CurrentO > CurrentV)
		{
			OCount += CurrentO;
		}
		else
		{
			VCount += CurrentV;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> R >> C;

	Board = vector<string>(R);
	Visit = vector<vector<bool>>(R, vector<bool>(C));

	for (int i = 0; i < R; ++i)
	{
		cin >> Board[i];
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Board[i][j] != '#' && Visit[i][j] == false)
			{
				BFS(i, j);
			}
		}
	}

	cout << OCount << ' ' << VCount << '\n';

	return 0;
}