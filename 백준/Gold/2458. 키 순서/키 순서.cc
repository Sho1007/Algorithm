#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
using namespace std;

int N, M, Small, Tall;

vector<bool> VisitVector;

int OrderMatrix[501][501] = {};

int FindTall(int Current)
{
	int Result = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (OrderMatrix[Current][i] == 1 && VisitVector[i] == false)
		{
			Result++;
			VisitVector[i] = true;
			Result += FindTall(i);
		}
	}

	return Result;
}

int FindSmall(int Current)
{
	int Result = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (OrderMatrix[Current][i] == -1 && VisitVector[i] == false)
		{
			Result++;
			VisitVector[i] = true;
			Result += FindSmall(i);
		}
	}

	return Result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> Small >> Tall;

		OrderMatrix[Small][Tall] = 1;
		OrderMatrix[Tall][Small] = -1;
	}

	int Answer = 0;

	for (int i = 1; i <= N; ++i)
	{
		VisitVector = vector<bool>(N + 1, false);
		int TotalCount = 0;

		// 큰 키 찾기
		TotalCount += FindTall(i);

		// 작은 키 찾기
		TotalCount += FindSmall(i);

		//cout << i << " : " << TotalCount << '\n';
		if (TotalCount == N - 1)
		{
			Answer++;
		}
	}

	cout << Answer << '\n';

	return 0;
}