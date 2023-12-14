#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int Max(int A, int B) { return A > B ? A : B; }

string A, B;

vector<vector<int>> CountArray;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B;

	CountArray = vector<vector<int>>(A.size() + 1, vector<int>(B.size() + 1));

	for (int i = 0; i <= A.size(); ++i)
	{
		for (int j = 0; j <= B.size(); ++j)
		{
			if (i == 0 || j == 0)
			{
				CountArray[i][j] = 0;
				continue;
			}
			if (A[i-1] == B[j-1])
			{
				CountArray[i][j] = CountArray[i - 1][j - 1] + 1;
			}
			else
			{
				CountArray[i][j] = Max(CountArray[i-1][j], CountArray[i][j-1]);
			}
		}
	}

	int Y = A.size(), X = B.size();
	string Answer = "";

	cout << CountArray[Y][X] << '\n';

	while (CountArray[Y][X] != 0)
	{
		if (CountArray[Y-1][X] < CountArray[Y][X] && CountArray[Y][X-1] < CountArray[Y][X])
		{
			Answer += A[Y - 1];
			Y--;
			X--;
		}
		else
		{
			if (CountArray[Y - 1][X] > CountArray[Y][X - 1]) Y--;
			else X--;
		}
	}

	reverse(Answer.begin(), Answer.end());
	cout << Answer << '\n';

	return 0;
}