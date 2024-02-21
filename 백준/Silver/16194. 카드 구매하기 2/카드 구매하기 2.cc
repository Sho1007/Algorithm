#pragma GCC optimize("ofast")
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Cost;

void Calc()
{
	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= i / 2; ++j)
		{
			int Current = Cost[j] + Cost[i - j];
			if (Current < Cost[i]) Cost[i] = Current;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	Cost = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
	}

	Calc();

	cout << Cost[N] << '\n';


	return 0;
}