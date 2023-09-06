#include <iostream>
#include <queue>
using namespace std;

int N;
queue<pair<int,int>> Q;
int DP[1'000'001] = {};
int Before[1'000'001] = {};
int NextNum;

void Find(int N)
{
	cout << N << ' ';
	if (Before[N] == 0)
	{
		cout << '\n';
	}
	else
	{
		Find(Before[N]);
	}
}

void Calc()
{
	Q.push({ 1, 0 });

	while(!Q.empty())
	{
		pair<int,int> CurrentData = Q.front(); Q.pop();

		if (DP[CurrentData.first] == -1 || DP[CurrentData.first] > DP[CurrentData.second] + 1)
		{
			DP[CurrentData.first] = DP[CurrentData.second] + 1;
			Before[CurrentData.first] = CurrentData.second;
			NextNum = CurrentData.first * 2;
			if (NextNum <= N)
			{

				Q.push({ NextNum, CurrentData.first });
			}

			NextNum = CurrentData.first * 3;
			if (NextNum <= N && (DP[NextNum] == -1 || DP[NextNum] > DP[CurrentData.first] + 1))
			{
				Q.push({ NextNum, CurrentData.first });
			}
			NextNum = CurrentData.first + 1;
			if (NextNum <= N && (DP[NextNum] == -1 || DP[NextNum] > DP[CurrentData.first] + 1))
			{
				Q.push({ NextNum, CurrentData.first });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cout.tie(0);

	cin >> N;

	fill(DP, DP + N + 1, -1);
	
	Calc();

	cout << DP[N] << '\n';
	Find(N);

	return 0;
}