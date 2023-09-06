#include <iostream>
using namespace std;

int F, S, G, U, D;

int MaxHeight;
int GoalFloor;
int CurrentFloor;
int UpStep;
int DownStep;

int DP[1'000'001] = {};

int Calc(int Pos, int Cost)
{
	if (DP[Pos] == -1 || DP[Pos] > Cost + 1)
	{
		DP[Pos] = Cost;

		/*cout << Pos << " : ";

		for (int i = 1; i <= MaxHeight; ++i)
		{
			cout << DP[i] << ' ';
		}
		cout << '\n';*/

		if (Pos + UpStep <= MaxHeight)
		{
			Calc(Pos + UpStep, DP[Pos] + 1);
		}

		if (Pos - DownStep >= 1)
		{
			Calc(Pos - DownStep, DP[Pos] + 1);
		}
	}

	return DP[Pos];
}

int main()
{
	ios::sync_with_stdio(0);

	cin >> MaxHeight >> CurrentFloor >> GoalFloor >> UpStep >> DownStep;

	fill(DP, DP + 1'000'001, -1);

	Calc(CurrentFloor, 0);

	if (DP[GoalFloor] == -1)
	{
		cout << "use the stairs\n";
	}
	else
	{
		cout << DP[GoalFloor] << '\n';
	}


	return 0;
}