#include <iostream>
#include <vector>
using namespace std;

int N;
int DP[1'500'002] = {};
int Value[1'500'002] = {};
int Cost[1'500'002] = {};

int CurValue1;
int CurValue2;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); 

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
		cin >> Value[i];
	}

	for (int i = N; i > 0; --i)
	{
		CurValue1 = 0;
		CurValue2 = 0;

		if (i + Cost[i] - 1 <= N)
		{
			CurValue1 += Value[i];
		}
		if (i + Cost[i] <= N)
		{
			CurValue1 += DP[i + Cost[i]];
		}
		CurValue2 = DP[i + 1];

		DP[i] = CurValue1 > CurValue2 ? CurValue1 : CurValue2;
	}

	cout << DP[1] << '\n';

	return 0;
}