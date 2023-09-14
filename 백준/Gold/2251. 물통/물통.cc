#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int Capacity[3];
int Input;

queue<vector<int>> Q;
set<int> Answer;
set<vector<int>> Set;
vector<int> Current;
int Water;
int main()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> Capacity[i];
	}

	Q.push({ 0, 0, Capacity[2] });
	Set.insert({ 0, 0, Capacity[2] });

	while (!Q.empty())
	{
		Current = Q.front(); Q.pop();

		for (int i = 0; i < 3; ++i)
		{
			if (Current[i] > 0)
			{
				for (int j = 0; j < 3; ++j)
				{
					// i -> j 로 물 주기
					if (i == j) continue;
					Water = Capacity[j] - Current[j];
					Water = Water < Current[i] ? Water : Current[i];
					Current[i] -= Water;
					Current[j] += Water;
					if (Set.find(Current) == Set.end())
					{
						Set.insert(Current);
						Q.push(Current);
					}
					Current[i] += Water;
					Current[j] -= Water;
				}
			}
		}
	}

	for (auto Iter : Set)
	{
		if (Iter[0] == 0) Answer.insert(Iter[2]);
	}

	for (int Iter : Answer)
	{
		cout << Iter << ' ';
	}
	cout << '\n';

	return 0;
}