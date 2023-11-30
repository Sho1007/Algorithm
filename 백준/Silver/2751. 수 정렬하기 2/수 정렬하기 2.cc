#include <iostream>
#include <algorithm>

using namespace std;

int N;

int arr[1'000'000];

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}