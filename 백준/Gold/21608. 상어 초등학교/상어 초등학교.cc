#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int N, StudentInput, Answer = 0;
int StudentNum;

vector<vector<int>> LikeVector;
vector<vector<int>> SeatVector;
vector<vector<int>> EmptyVector;

void Print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << SeatVector[i][j] << ' ';
		}
		cout << '\n';
	}
}

int CheckSeat(int YPos, int XPos, int CurrentStudent)
{
	int NextY, NextX, Result = 0;
	for (int i = 0; i < 4; ++i)
	{
		NextY = YPos + dy[i];
		NextX = XPos + dx[i];

		if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;
		if (SeatVector[NextY][NextX] == 0) Result++;
		else
		{
			for (int j = 0; j < LikeVector[CurrentStudent].size(); ++j)
			{
				if (SeatVector[NextY][NextX] == LikeVector[CurrentStudent][j])
				{
					Result += 10;
					break;
				}
			}
		}
	}

	return Result;
}

int CheckScore(int YPos, int XPos, int CurrentStudent)
{
	int NextY, NextX, Result = 0;

	for (int i = 0; i < 4; ++i)
	{
		NextY = YPos + dy[i];
		NextX = XPos + dx[i];
		if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;

		for (int j = 0; j < LikeVector[CurrentStudent].size(); ++j)
		{
			if (SeatVector[NextY][NextX] == LikeVector[CurrentStudent][j])
			{
				Result++;
				break;
			}
		}
	}

	switch(Result)
	{
	case 2:
		Result = 10;
		break;
	case 3:
		Result = 100;
		break;
	case 4:
		Result = 1000;
		break;
	}

	return Result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	StudentNum = N * N;

	LikeVector = vector<vector<int>>(StudentNum + 1, vector<int>(4));
	SeatVector = vector<vector<int>>(N, vector<int>(N, 0));
	EmptyVector = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < StudentNum; ++i)
	{
		cin >> StudentInput;
		for (int i = 0; i < 4; ++i)
		{
			cin >> LikeVector[StudentInput][i];
		}

		int MaxValue = -1, Current;
		pair<int, int> MaxPos;
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (SeatVector[j][k] != 0) continue;
				Current = CheckSeat(j, k, StudentInput);
				if (Current > MaxValue)
				{
					MaxValue = Current;
					MaxPos = { j, k };
				}
			}
		}

		SeatVector[MaxPos.first][MaxPos.second] = StudentInput;
		//Print();
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Answer += CheckScore(i, j, SeatVector[i][j]);
		}
	}

	cout << Answer << '\n';

	return 0;
}