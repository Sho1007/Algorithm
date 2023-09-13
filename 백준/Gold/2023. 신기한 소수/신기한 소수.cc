#include <iostream>
#include <cmath>
using namespace std;

int N;
int FirstNumArray[4] = { 2, 3, 5, 7 };

void FindPrime(int Num, int Length)
{
	if (N == Length)
	{
		cout << Num << '\n';
		return;
	}
	Num *= 10;

	int CheckNum;
	int Sqrt;
	bool bIsPrime;
	for (int i = 0; i < 10; ++i)
	{
		CheckNum = Num + i;
		Sqrt = sqrt(CheckNum);
		bIsPrime = true;
		for (int j = 2; j <= Sqrt; ++j)
		{
			if (CheckNum % j == 0)
			{
				bIsPrime = false;
				break;
			}
		}
		if (bIsPrime) FindPrime(CheckNum, Length + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < 4; ++i)
	{
		FindPrime(FirstNumArray[i], 1);
	}


	return 0;
}