#include <iostream>
#include <queue>
using namespace std;
#define MAX 1002

int S;

vector<int> DP;

struct COMP
{
	bool operator()(int A, int B)
	{
		return DP[A] > DP[B];
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> S;

	DP = vector<int>(MAX + 1, 987'654'321);

	DP[0] = 0;
	DP[1] = 0;

	priority_queue<int, vector<int>, COMP> Queue;

	Queue.push(1);

	while (Queue.empty() == false)
	{
		int Current = Queue.top(); Queue.pop();

		// BACK
		int BackCost = DP[Current] + 1;
		if (DP[Current - 1] > BackCost)
		{
			DP[Current - 1] = BackCost;
			Queue.push(Current - 1);
		}

		for (int i = 2; Current * i <= MAX; ++i)
		{
			int Cost = DP[Current] + 1 + (i - 1);
			if (DP[Current * i] > Cost)
			{
				DP[Current * i] = Cost;
				Queue.push(Current * i);
			}
		}
	}

	for (int i = 1; i < DP.size(); ++i)
	{
		for (int j = 1; i * j <= MAX; ++j)
		{
			int Cost = DP[i] + 1 + (j - 1);
			if (DP[i * j] > Cost)
			{
				DP[i * j] = Cost;
			}
		}
	}

	cout << DP[S] << '\n';

	return 0;
}