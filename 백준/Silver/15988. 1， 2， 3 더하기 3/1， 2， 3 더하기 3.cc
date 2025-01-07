#include <iostream>
#include <vector>
#define MOD 1'000'000'009
using namespace std;

unsigned int N, Input;
unsigned int  DP[1'000'001] = {};


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (unsigned int i = 4; i <= 1'000'000; ++i)
	{
		for (unsigned int j = 1; j <= 3; ++j)
		{
			DP[i] += DP[i - j];
			DP[i] %= MOD;
		}
	}

	while (N-- > 0)
	{
		cin >> Input;
		cout << DP[Input] << '\n';
	}

	return 0;
}