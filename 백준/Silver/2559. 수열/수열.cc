#include <iostream>

#define endl "\n"

using namespace std;

int N, K;

int* sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	sum = new int[N];

	int num;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		if (i == 0)
			sum[i] = num;
		else
			sum[i] = sum[i - 1] + num;
	}

	int start = K-1;
	int max = -999'999'999;
	for (int i = start; i < N; ++i)
	{
		int num;
		if (i == start)
		{
			num = sum[i];
		}
		else
		{
			num = sum[i] - sum[i - K];
			
		}
		if (num > max)
			max = num;

		
	}
	cout << max << endl;

	delete[] sum;

	return 0;
}