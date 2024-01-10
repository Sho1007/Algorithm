#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> Board, DP;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void Print()
{
	cout << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Board[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}
}

int Calc(int Y, int X)
{
	if (DP[Y][X] == -1)
	{
		int Max = -1;
		for (int i = 0; i < 4; ++i)
		{
			int NextY = Y + dy[i];
			int NextX = X + dx[i];

			if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N) continue;
			if (Board[NextY][NextX] <= Board[Y][X]) continue;
			int Current = Calc(NextY, NextX);
			if (Max < Current) Max = Current;
		}
		DP[Y][X] = Max + 1;
	}

	return DP[Y][X];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Board = vector<vector<int>>(N, vector<int>(N));
	DP = vector<vector<int>>(N, vector<int>(N, -1));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Board[i][j];
		}
	}

	int Max = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Current = Calc(i, j);
			if (Current > Max) Max = Current;
		}
	}

	cout << Max + 1 << '\n';

	return 0;
}