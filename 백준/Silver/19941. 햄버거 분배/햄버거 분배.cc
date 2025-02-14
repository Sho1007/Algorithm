#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, Answer = 0;
string Banch;
bool Find;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K >> Banch;


	for (int i = 0; i < N; ++i)
	{
		// 사람인 경우
		if (Banch[i] == 'P')
		{
			Find = false;
			// 왼쪽 가장 먼 곳 부터 햄버거를 탐색
			for (int j = max(i - K, 0); j < i; ++j)
			{
				if (Banch[j] == 'H')
				{
					Find = true;
					Banch[j] = ' ';
					Answer++;
					break;
				}
			}
			if (Find) continue;

			// 오른쪽부터 최대 거리까지 햄버거를 탐색
			for (int j = i + 1; j < N && j <= i + K; ++j)
			{
				if (Banch[j] == 'H')
				{
					Banch[j] = ' ';
					Answer++;
					break;
				}
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}