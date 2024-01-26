#include <iostream>
#include <queue>
using namespace std;

vector<int> NeedCount;
vector<int> Cost;
vector<int> Time;
vector<vector<int>> NeedStructure;
int N, Input;

int Calc(int Pos)
{
	if (Time[Pos] == 0)
	{
		Time[Pos] = Cost[Pos];
		int Max = 0;
		for (int i = 0; i < NeedStructure[Pos].size(); ++i)
		{
			int CurrentTime = Calc(NeedStructure[Pos][i]);
			if (CurrentTime > Max) Max = CurrentTime;
		}

		Time[Pos] += Max;
	}

	return Time[Pos];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	NeedCount = vector<int>(N + 1, 0);
	Cost = vector<int>(N + 1);
	Time = vector<int>(N + 1, 0);
	NeedStructure = vector<vector<int>>(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> Cost[i];
		cin >> Input;
		while (Input != -1)
		{
			NeedStructure[i].push_back(Input);

			cin >> Input;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Calc(i) << '\n';
	}

	return 0;
}