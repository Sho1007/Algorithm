#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, Answer = 1;
vector<string> V;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	V = vector<string>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> V[i];
		for (int j = 0; j < M; ++j)
		{
			for (int k = 1;; ++k)
			{
				int Left = j - k;
				int Top = i - k;
				if (Left < 0 || Top < 0) break;

				if (V[i][j] == V[Top][Left] && V[i][j] == V[Top][j] && V[i][j] == V[i][Left])
				{
					int Area = (k + 1) * (k + 1);
					Answer = Answer >= Area ? Answer : Area;
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}