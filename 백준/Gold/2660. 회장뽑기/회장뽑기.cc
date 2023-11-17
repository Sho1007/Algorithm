#include <iostream>
#include <vector>
#include <map>
#define INF 987'654'321
using namespace std;

int N, Start, End;
vector<vector<int>> Cost;
map<int, vector<int>> Map;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Cost = vector<vector<int>>(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; ++i)
	{
		Cost[i][i] = 0;
	}

	while (true)
	{
		cin >> Start >> End;

		if (Start == -1 && End == -1) break;

		Cost[Start][End] = 1;
		Cost[End][Start] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (Cost[i][k] + Cost[k][j] < Cost[i][j])
				{
					Cost[i][j] = Cost[i][k] + Cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		int MaxValue = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (MaxValue < Cost[i][j]) MaxValue = Cost[i][j];
		}

		Map[MaxValue].push_back(i);
	}

	for (auto Iter : Map)
	{
		cout << Iter.first << ' ' << Iter.second.size() << '\n';
		for (int i = 0; i < Iter.second.size(); ++i)
		{
			cout << Iter.second[i] << ' ';
		}
		cout << '\n';
		break;
	}

	return 0;
}