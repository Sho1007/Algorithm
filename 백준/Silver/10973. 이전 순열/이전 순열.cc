#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, LastPos = -1, TargetNum, ReplacePos, ReplaceNum;

vector<int> V;

void Print()
{
	for (int i = 0; i < N; ++i)
	{
		cout << V[i] << ' ';
	}

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	V = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> V[i];

		if (i > 0 && V[i] < V[i - 1])
		{
			LastPos = i - 1;
			TargetNum = V[i - 1];
		}
	}

	if (LastPos == -1)
	{
		cout << LastPos << '\n';
	}
	else
	{
		sort(V.begin() + LastPos, V.end(), [](int A, int B)->bool
		{
				return A > B;
		});

		for (int j = LastPos; j < N; ++j)
		{
			if (V[j] == TargetNum)
			{
				ReplacePos = j + 1;
				ReplaceNum = V[j + 1];
				break;
			}
		}

		V.erase(V.begin() + ReplacePos);
		V.insert(V.begin() + LastPos, ReplaceNum);

		Print();
	}

	return 0;
}