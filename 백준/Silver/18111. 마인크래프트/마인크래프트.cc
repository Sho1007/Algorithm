#include <iostream>
using namespace std;

int N, M, B;

int Board[500][500] = {};

int MinHeight = 257;
int MaxHeight = -1;

int TimeArray[257] = {};

int MinCost = 987'654'321;
int TargetHeight = 0;

int GetTime(int TargetHeight)
{
	int Add = 0;
	int Sub = 0;
	int Current;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Current = TargetHeight - Board[i][j];
			if (Current >= 0) Add += Current;
			else Sub -= Current;
		}
	}

	if (Sub + B < Add) return 987'654'321;

	return Add + (Sub * 2);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> B;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Board[i][j];
			if (Board[i][j] < MinHeight) MinHeight = Board[i][j];
			if (Board[i][j] > MaxHeight) MaxHeight = Board[i][j];
		}
	}

	int Cost = 987'654'321;
	int OldCost = 0;
	for (int i = MinHeight; i <= MaxHeight; ++i)
	{
		OldCost = Cost;

		Cost = GetTime(i);

		//cout << Cost << '\n';

		if (Cost > OldCost) break;
		MinCost = Cost;
		TargetHeight = i;
	}

	cout << MinCost << ' ' << TargetHeight << '\n';

	return 0;
}