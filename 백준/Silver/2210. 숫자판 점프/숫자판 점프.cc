#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

char Board[5][5] = {};
int DX[4] = { 0, 0, -1, 1 };
int DY[4] = { -1, 1, 0, 0 };
unordered_set<string> Set;

void FindString(int X, int Y, int MoveCount, string& ResultString)
{
	if (MoveCount == 5)
	{
		Set.insert(ResultString);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int NextX = X + DX[i];
		int NextY = Y + DY[i];

		if (NextX < 0 || NextX > 4 || NextY < 0 || NextY > 4) continue;

		ResultString += Board[NextX][NextY];
		FindString(NextX, NextY, MoveCount + 1, ResultString);
		ResultString.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> Board[i][j];
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			string ResultString = "";
			ResultString += Board[i][j];
			FindString(i, j, 0, ResultString);
		}
	}

	cout << Set.size() << '\n';

	return 0;
}