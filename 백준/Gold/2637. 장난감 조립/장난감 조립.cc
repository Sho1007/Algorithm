#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<pair<int, int>>> Ingredient;

map<int, int> Result;

vector<map<int, int>> DP;

map<int,int> Calc (int CurrentNum)
{
	if (DP[CurrentNum].empty())
	{
		if (Ingredient[CurrentNum].size() == 0)
		{
			DP[CurrentNum][CurrentNum] = 1;
		}
		else
		{
			for (int i = 0; i < Ingredient[CurrentNum].size(); ++i)
			{
				const map<int, int>& CurrentMap = Calc(Ingredient[CurrentNum][i].first);

				for (auto Iter : CurrentMap)
				{
					DP[CurrentNum][Iter.first] += Iter.second * Ingredient[CurrentNum][i].second;
				}
			}
		}
	}

	return DP[CurrentNum];
}


int N, M, X, Y, K;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	DP = vector<map<int, int>>(N + 1);

	while (M-->0)
	{
		cin >> X >> Y >> K;

		Ingredient[X].push_back({ Y, K });
	}

	Result = Calc(N);

	for (auto Iter : Result)
	{
		cout << Iter.first << ' ' << Iter.second << '\n';
	}


	return 0;
}