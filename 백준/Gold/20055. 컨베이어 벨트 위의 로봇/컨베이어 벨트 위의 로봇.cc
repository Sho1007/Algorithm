#include <iostream>
#include <vector>
using namespace std;

int N, K, Turn = 0, ZeroCount = 0;
vector<int> V;
vector<bool> R;

int main()
{
	cin >> N >> K;

	V = vector<int>(2 * N, 0);
	R = vector<bool>(2 * N, false);

	for (int i = 0; i < 2 * N; ++i)
	{
		cin >> V[i];
	}

	while (true)
	{
		Turn++;

		// 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		V.insert(V.begin(), V.back());
		V.pop_back();
		R.insert(R.begin(), R.back());
		R.pop_back();

		if (R[N - 1]) R[N - 1] = false;

		for (int i = N - 1; i >= 0; --i)
		{
			if (R[i] == false) continue;

			// 이동할 수 있으면 이동
			if (R[i + 1] == false && V[i + 1] > 0)
			{
				if (--V[i + 1] == 0) ZeroCount++;
				if (ZeroCount == K)
				{
					cout << Turn << '\n';
					return 0;
				}
				if (i + 1 != N - 1) R[i + 1] = true;
				R[i] = false;
			}
		}

		if (V[0] > 0)
		{
			if (--V[0] == 0) ZeroCount++;
			if (ZeroCount == K)
			{
				cout << Turn << '\n';
				return 0;
			}
			R[0] = true;
		}
	}
	
	return 0;
}