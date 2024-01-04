#include <iostream>
#include <queue>
using namespace std;

inline int ABS(pair<int,int> A, pair<int,int> B)
{
	int Result1 = (A.first - B.first);
	if (Result1 < 0) Result1 *= -1;

	int Result2 = (A.second - B.second);
	if (Result2 < 0) Result2 *= -1;

	return Result1 + Result2;
}

int N;
int Board[100][100] = {};
bool Visit[100][100] = {};

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

vector<vector<pair<int,int>>> OutLineVector;

void BFS(int Y, int X)
{
	vector<pair<int, int>> CurrentOutLine;
	queue<pair<int, int>> Queue;

	Visit[Y][X] = true;

	Queue.push({ Y, X });

	while (Queue.empty() == false)
	{
		pair<int, int> Current = Queue.front(); Queue.pop();

		int SeaCount = 0;
		for (int i = 0; i < 4; ++i)
		{
			int NextY = Current.first + dy[i];
			int NextX = Current.second + dx[i];

			if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;
			if (Board[NextY][NextX] == 0)
			{
				SeaCount++;
				continue;
			}
			if (Board[NextY][NextX] == 1 && Visit[NextY][NextX] == true) continue;

			Visit[NextY][NextX] = true;
			Queue.push({ NextY, NextX });
		}
		if (SeaCount > 0) CurrentOutLine.push_back(Current);
	}

	OutLineVector.push_back(CurrentOutLine);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Board[i][j];
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (Board[i][j] == 1 && Visit[i][j] == false)
			{
				BFS(i, j);
			}
		}
	}

	int MinValue = 987'654'321;

	for (int i = 0; i < OutLineVector.size(); ++i)
	{
		for (int j = i + 1; j < OutLineVector.size(); ++j)
		{
			for (auto Iter1 : OutLineVector[i])
			{
				for (auto Iter2 : OutLineVector[j])
				{
					int Current = ABS(Iter1, Iter2);
					if (Current < MinValue) MinValue = Current;
				}
			}
		}
	}


	cout << MinValue - 1 << '\n';

	return 0;
}