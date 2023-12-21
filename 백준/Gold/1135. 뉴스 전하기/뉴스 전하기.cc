#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int MAX(int A, int B) { return A > B ? A : B; }

int N, Input;
vector<vector<int>> SubordVector;
vector<int> CostVector;

int DP(int Current)
{
	if (SubordVector[Current].size() == 0)
	{
		CostVector[Current] = 0;
	}
	else
	{
		for (int i = 0; i < SubordVector[Current].size(); ++i)
		{
			DP(SubordVector[Current][i]);
		}

		if (SubordVector[Current].size() > 1)
		{
			sort(SubordVector[Current].begin(), SubordVector[Current].end(), [](int A, int B)->bool
				{
					return CostVector[A] > CostVector[B];
				});
		}

		int MaxValue = 0;

		for (int i = 0; i < SubordVector[Current].size(); ++i)
		{
			CostVector[SubordVector[Current][i]] += (i + 1);
			if (CostVector[SubordVector[Current][i]] > MaxValue) MaxValue = CostVector[SubordVector[Current][i]];
		}

		CostVector[Current] = MaxValue;
	}

	return CostVector[Current];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	SubordVector = vector<vector<int>>(N);

	CostVector = vector<int>(N, 987'654'321);

	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		if (Input != -1)
		{
			SubordVector[Input].push_back(i);
		}
	}

	DP(0);

	cout << CostVector[0] << '\n';

	return 0;
}