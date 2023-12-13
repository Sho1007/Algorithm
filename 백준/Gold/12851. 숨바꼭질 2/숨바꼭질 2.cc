#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int N, K;

int CostArray[100'001] = {};
int CountArray[100'001] = {};
//map<int, set<int>> Map;

queue<int> Queue;

void Calculate(int Current, int Next)
{
	if (CostArray[Next] == -1 || CostArray[Next] > CostArray[Current] + 1)
	{
		CostArray[Next] = CostArray[Current] + 1;
		CountArray[Next] = CountArray[Current];
		/*Map[Next].clear();
		Map[Next].insert(Current);*/
		Queue.push(Next);
	}
	else if (CostArray[Next] == CostArray[Current] + 1)
	{
		/*if (Map[Next].find(Current) == Map[Next].end())
		{
			Map[Next].insert(Current);
			CountArray[Next] += CountArray[Current];
		}*/

		CountArray[Next] += CountArray[Current];
	}
}

void Find()
{
	CostArray[N] = 0;
	CountArray[N] = 1;
	Queue.push(N);

	while (Queue.empty() == false)
	{
		int Current = Queue.front(); Queue.pop();
		int Next;

		Next = Current - 1;
		if (0 <= Next)
		{
			Calculate(Current, Next);
		}

		Next = Current + 1;

		if (Next <= 100'000)
		{
			Calculate(Current, Next);
		}

		Next = Current * 2;

		if (Next <= 100'000)
		{
			Calculate(Current, Next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	fill(CostArray, CostArray + 100'001, -1);

	Find();

	cout << CostArray[K] << '\n';
	cout << CountArray[K] << '\n';

	/*for (int i = 1; i <= 5; ++i)
	{
		cout << i << " : ";
		for (auto Iter : Map[i])
		{
			cout << Iter << ' ';
		}
		cout << "\n";
	}*/

	return 0;
}