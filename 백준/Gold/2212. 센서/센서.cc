#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, K, Input;
int Answer = 0, Count;

set<int> PosSet;
vector<int> PosVector;

priority_queue<int, vector<int>, greater<int>> DeltaQueue;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> Input;
		PosSet.insert(Input);
	}

	PosVector = vector<int>(PosSet.begin(), PosSet.end());

	Count = PosVector.size();

	if (Count <= K)
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < PosVector.size()-1; ++i)
	{
		DeltaQueue.push(PosVector[i + 1] - PosVector[i]);
	}

	while (DeltaQueue.empty() == false)
	{
		Answer += DeltaQueue.top(); DeltaQueue.pop();
		if (--Count <= K) break;
	}

	cout << Answer << '\n';

	return 0;
}