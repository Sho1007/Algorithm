#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, Answer = 0;
int* Array;
map <int, vector<int>> Map;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Array = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> Array[i];
		Map[Array[i]].push_back(i);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			int Current = Array[i] + Array[j];

			if (Map.find(Current) != Map.end())
			{
				for (int k = 0; k < Map[Current].size();)
				{
					if (Map[Current][k] != i && Map[Current][k] != j)
					{
						Answer++;
						Map[Current].erase(Map[Current].begin() + k);
					}
					else
					{
						++k;
					}
				}
			}
		}
	}

	cout << Answer << '\n';

	delete[] Array;

	return 0;
}