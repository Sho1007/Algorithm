#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<string> Board;
vector<vector<bool>> Visit;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void PrintBoard()
{
	cout << '\n';
	for (int i = 0; i < Board.size(); ++i)
	{
		cout << Board[i] << '\n';
	}
}

bool BFS(int Y, int X)
{
	int Count = 0;
	queue<pair<int, int>> Queue;
	vector<pair<int, int>> PosVector;
	PosVector.push_back({ Y, X });
	Queue.push({ Y, X });
	char Color = Board[Y][X];
	Visit[Y][X] = true;
	Count++;

	while (Queue.empty() == false)
	{
		pair<int, int> Current = Queue.front(); Queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= Board.size() || NextX < 0 || NextX >= Board[0].size()) continue;
			if (Board[NextY][NextX] != Color || Visit[NextY][NextX] == true) continue;

			Count++;
			Visit[NextY][NextX] = true;
			PosVector.push_back({ NextY, NextX });
			Queue.push({ NextY, NextX });
		}
	}

	if (Count >= 4)
	{
		// 터짐
		for (int i = 0 ; i < PosVector.size(); ++i)
		{
			Board[PosVector[i].first][PosVector[i].second] = '.';
		}

		return true;
	}

	return false;
}

// 백준 11559 문제 (계속 풀기)
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Board = vector<string>(12);

	for (int i = 0; i < Board.size(); ++i)
	{
		cin >> Board[i];
	}

	int Answer = 0;

	bool bIsChained = true;
	while (bIsChained)
	{
		// Check Chain

		bIsChained = false;
		Visit = vector<vector<bool>>(12, vector<bool>(6, false));
		for (int i = 0; i < Board.size(); ++i)
		{
			for (int j = 0; j < Board[i].size(); ++j)
			{
				if (Board[i][j] != '.' && Visit[i][j] == false)
				{
					if (BFS(i, j))
					{
						bIsChained = true;
					}
				}
			}
		}

		if (bIsChained == false)
		{
			break;
		}

		// PrintBoard();

		Answer++;

		// Move To Bottom

		for (int j = 0; j < 6; ++j)
		{
			for (int i = Board.size()-1; i >= 0; --i)
			{
				// 빈칸 찾기
				if (Board[i][j] == '.')
				{
					int CurrentPos = i;
					for (int k = i - 1; k >= 0; --k)
					{
						// 그 위에 비어 있지 않은 칸 찾기
						if (Board[k][j] != '.')
						{
							CurrentPos = k;
							break;
						}
					}

					if (CurrentPos == i) continue;

					for (int k = i; k >= 0; --k)
					{
						if (CurrentPos >= 0)
						{
							Board[k][j] = Board[CurrentPos--][j];
						}
						else
						{
							Board[k][j] = '.';
						}
					}
				}
			}
		}

		// PrintBoard();
	}

	cout << Answer << '\n';

	return 0;
}