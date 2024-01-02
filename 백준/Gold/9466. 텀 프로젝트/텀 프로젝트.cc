#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
vector<int> Vector;
vector<bool> Visit;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	Vector = vector<int>(100'001, 0);
	Visit = vector<bool>(100'001, false);

	while (T-->0)
	{
		cin >> N;

		fill(Visit.begin(), Visit.begin() + N + 1, false);

		for (int i = 1; i <= N; ++i)
		{
			cin >> Vector[i];
		}

		int Answer = 0;

		for (int i = 1; i <= N; ++i)
		{
			if (Visit[i]) continue;

			int Current = i;
			vector<int> Loop;

			Loop.push_back(Current);
			Visit[Current] = true;

			while (true)
			{
				Current = Vector[Current];

				// 이미 방문한 적이 있는 경우
				if (Visit[Current] == true)
				{
					// Loop 발생
					if (Current == i) break;
					// 시작점이 i가 아닌 Loop 발생
					
					auto Iter = find(Loop.begin(), Loop.end(), Current);
					int Count = Iter - Loop.begin();

					Answer += Count;
					break;
				}
				else
				{
					Loop.push_back(Current);
					Visit[Current] = true;
				}
			}
		}

		cout << Answer << '\n';
	}

	return 0;
}