#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
bool bIsMakable = false;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> S >> T;

	while (T.size() >= S.size())
	{
		if (T == S)
		{
			bIsMakable = true;
			break;
		}
		else
		{
			if (T.back() == 'A') T.pop_back();
			else
			{
				T.pop_back();
				reverse(T.begin(), T.end());
			}
		}
	}

	cout << bIsMakable << '\n';

	return 0;
}