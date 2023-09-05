#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, LastPos = -1, LastNum;
vector<int> Array;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	Array = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Array[i];
		if (i > 0 && Array[i] > Array[i-1])
		{
			LastPos = i - 1;
			LastNum = Array[i - 1];
		}
	}

	if (LastPos == -1)
	{
		cout << "-1\n";	
	}
	else
	{
		sort(Array.begin() + LastPos, Array.end());

		int BiggerNum;
		for (int i = LastPos; i < N; ++i)
		{
			if (Array[i] > LastNum)
			{
				BiggerNum = Array[i];
				Array.erase(Array.begin() + i);

				break;
			}
		}
		Array.insert(Array.begin() + LastPos, BiggerNum);
		
		for (int i = 0; i < N; ++i)
		{
			cout << Array[i] << ' ';
		}
		cout << '\n';
	}


	return 0;
}