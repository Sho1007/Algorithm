#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

vector<int> PrimePalin;
vector<bool> IsPrime;

bool CheckPalindrome(int Target)
{
	string str = to_string(Target);
	const int length = str.length();
	const int half_length = length / 2;

	int bIsPalindrome = true;


	for (int j = 0; j < half_length; ++j)
	{
		if (str[j] != str[length - 1 - j])
		{
			// cout << str[j] << " != " << str[length - 1 - j] << '\n';
			bIsPalindrome = false;
			break;
		}
	}

	return bIsPalindrome;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	IsPrime = vector<bool>(2'000'001, true);

	cin >> N;

	for (int i = 2; i <= 2'000'000; ++i)
	{
		if (true == IsPrime[i])
		{
			// cout << i << '\n';
			for (int j = 2; j * i <= 2'000'000; ++j)
			{
				IsPrime[i * j] = false;
			}

			// check pelindrome

			if (CheckPalindrome(i) && N <= i)
			{
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}
