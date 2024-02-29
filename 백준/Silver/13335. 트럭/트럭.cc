#include <iostream>
#include <queue>
using namespace std;

int N, W, L, CurrentIndex = 0, Time = 1, TotalWeight = 0;
vector<int> TruckWeight;
queue<pair<int, int>> Queue;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> N >> W >> L;

	TruckWeight = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> TruckWeight[i];
	}

	TotalWeight += TruckWeight[CurrentIndex];
	// cout << TruckWeight[CurrentIndex] << ' ' << Time << '\n';
	Queue.push({ TruckWeight[CurrentIndex++], Time});

	while (!(TruckWeight.size() == CurrentIndex && Queue.empty()))
	{
		Time++;
		if (Queue.front().second + W <= Time)
		{
			TotalWeight -= Queue.front().first;
			Queue.pop();
		}

		if (CurrentIndex < TruckWeight.size() && TotalWeight + TruckWeight[CurrentIndex] <= L)
		{
			TotalWeight += TruckWeight[CurrentIndex];
			// cout << TruckWeight[CurrentIndex] << ' ' << Time << '\n';
			Queue.push({ TruckWeight[CurrentIndex++] , Time });
		}
	}

	cout << Time << '\n';
	

	return 0;
}