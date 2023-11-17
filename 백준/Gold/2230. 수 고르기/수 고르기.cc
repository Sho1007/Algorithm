#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, Diff = 2'000'000'001, CurrentDiff;

vector<int> Vector;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Vector = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Vector[i];
	}

	sort(Vector.begin(), Vector.end());

	int Left = 0, Right = 0;

	while (true)
	{
		if (Left > Right)
		{
			Right++;
			continue;
		}

		if (Right >= N) break;


		CurrentDiff = Vector[Right] - Vector[Left];
		if (CurrentDiff < M)
		{
			Right++;
		}
		else
		{
			if (CurrentDiff < Diff)
			{
				Diff = CurrentDiff;
				if (Diff == M) break;
			}
			Left++;
		}
	}

	cout << Diff << '\n';

	return 0;
}