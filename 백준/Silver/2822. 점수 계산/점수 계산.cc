#include <iostream>
#include <algorithm>
using namespace std;

int Score[8];
int Index[8];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 8; ++i)
	{
		cin >> Score[i];
		Index[i] = i;
	}

	sort(Index, Index + 8, [](int A, int B)->bool
		{
			return Score[A] < Score[B];
		});

	
	int Sum = 0;

	for (int i = 3; i < 8; ++i)
	{
		Sum += Score[Index[i]];
	}

	cout << Sum << '\n';

	sort(Index + 3, Index + 8);

	for (int i = 3; i < 8; ++i)
	{
		cout << Index[i] + 1 << ' ';
	}
	cout << '\n';


	return 0;
}