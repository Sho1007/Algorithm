#include <iostream>
#include <vector>
using namespace std;

int T, N, M, NowOrder;

int main()
{
	cin >> T;

	while (T-- > 0)
	{
		cin >> N >> M;
		NowOrder = 1;
		vector<pair<int, int>> Q = vector<pair<int,int>>(N);
		for (int i = 0; i < N; ++i)
		{
			Q[i].first = i;
			cin >> Q[i].second;
		}

		while (Q.size() > 0)
		{
			bool bIsPrintable = true;
			for (int i = 1; i < Q.size(); ++i)
			{
				if (Q[0].second < Q[i].second)
				{
					bIsPrintable = false;
					Q.push_back(Q[0]);
					Q.erase(Q.begin());
					break;
				}
			}
			if (bIsPrintable)
			{
				if (Q[0].first == M)
				{
					cout << NowOrder << '\n';
					break;
				}
				else
				{
					NowOrder++;
					Q.erase(Q.begin());
				}
			}
		}
	}

	return 0;
}