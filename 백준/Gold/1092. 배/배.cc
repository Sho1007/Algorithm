#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, Input, Answer = 0;

vector<int> CraneVector;
vector<int> BoxVector;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> N;

	CraneVector = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> CraneVector[i];
	}

	sort(CraneVector.begin(), CraneVector.end());

	cin >> M;
	BoxVector = vector<int>(N, 0);

	while (M-- > 0)
	{
		cin >> Input;
		if (Input > CraneVector.back())
		{
			cout << "-1\n";
			return 0;
		}
		for (int i = 0; i < CraneVector.size(); ++i)
		{
			if (Input <= CraneVector[i])
			{
				BoxVector[i]++;
				break;
			}
		}
	}

	for (int i = BoxVector.size() - 1; i >= 0 ; --i)
	{
		int BoxSum = 0;
		for (int j = i; j < BoxVector.size(); ++j)
		{
			BoxSum += BoxVector[j];
		}

		int AverageBox = BoxSum / (BoxVector.size() - i);

		if (BoxSum % (BoxVector.size() - i) != 0) AverageBox++;

		//cout << BoxSum << " / " << (BoxVector.size() - i) << ", AverageBox : " << AverageBox << '\n';

		if (AverageBox >= BoxVector[i]) continue;

		for (int j = i + 1; j < BoxVector.size(); ++j)
		{
			if (BoxVector[j] < AverageBox)
			{
				int AddableBoxCount = AverageBox - BoxVector[j];
				BoxVector[i] -= AddableBoxCount;
				BoxVector[j] += AddableBoxCount;
			}
		}
	}

	int Answer = 0;

	for (int i = 0; i < BoxVector.size(); ++i)
	{
		if (Answer < BoxVector[i]) Answer = BoxVector[i];
	}

	cout << Answer << '\n';

	return 0;
}