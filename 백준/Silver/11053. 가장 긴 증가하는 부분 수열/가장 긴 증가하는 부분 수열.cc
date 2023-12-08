#include <iostream>
#include <vector>

using namespace std;

int N;

int* arr;

int result[1'000] = {};

int maxResult = 0;

void Func(int pos)
{
	int max = 1;
	for (int i = pos + 1; i < N; ++i)
	{
		if (arr[i] > arr[pos])
		{
			if (result[i] >= max)
				max = result[i] + 1;
		}
	}
	result[pos] = max;

	if (max > maxResult)
		maxResult = max;


	if (pos == 0) return;

	Func(pos - 1);
}

int main()
{
	ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	cin >> N;

	arr = new int[N];

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	Func(N-1);

	cout << maxResult << "\n";

	delete[] arr;

	return 0;
}