#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

unsigned long long Sum;

vector<unsigned long long> Trees;

unsigned long long Left, Mid, Right;

int main()
{
	int Answer;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Trees = vector<unsigned long long>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Trees[i];
	}

	sort(Trees.begin(), Trees.end());

	Left = 0;
	Right = Trees.back();

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		// Do Some
		Sum = 0;
		for (int i = 0; i < Trees.size(); ++i)
		{
			if (Trees[i] > Mid) Sum += (Trees[i] - Mid);
		}

		//cout << Mid << " : " << Sum << '\n';

		if (Sum >= M)
		{
			Answer = Mid;
			Left = Mid + 1;
		}
		else
		{
			Right = Mid - 1;
		}
	}

	cout << Answer << '\n';

	return 0;
}