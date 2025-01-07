#include <iostream>
#include <vector>
#define MOD 1'000'000'009
using namespace std;

int N, Input;
unsigned long long  DP[1'000'001] = {};

int Calc(int Num)
{
	if (DP[Num] == 0)
	{
		unsigned long long Sum = 0;
		if (0 < Num && Num <= 3)
		{
			Sum++;
		}

		for (int i = 1; i <= 3; ++i)
		{
			if (Num - i == 0)
			{
				break;
			}

			Sum += Calc(Num - i);
			Sum %= MOD;
		}

		DP[Num] = Sum;
	}

	return DP[Num];
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	while (N-- > 0)
	{
		cin >> Input;
		cout << Calc(Input) << '\n';
	}

	return 0;
}