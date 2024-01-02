#include <iostream>

#define endl "\n"

using namespace std;

int N;

int answer = 0;

int* arr;

void Init()
{
	cin >> N;

	arr = new int[N];
	fill_n(arr, N, -1);
}

bool Check(int num)
{
	for (int i = 0; i < num; ++i)
	{
		if (arr[i] == arr[num] || abs(arr[i] - arr[num]) == num - i) return false;
	}
	return true;
}

void NQueen(int count)
{
	if (count == N)
		answer++;
	else
	{
		for (int i = 0; i < N; ++i)
		{
			arr[count] = i;
			if (Check(count))
				NQueen(count + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	Init();
	

	NQueen(0);

	cout << answer << endl;

	return 0;
}