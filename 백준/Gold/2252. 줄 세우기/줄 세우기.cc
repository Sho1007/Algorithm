#include <iostream>
#include <queue>
using namespace std;

int N, M, A, B;

vector<pair<int, vector<int>>> StudentVector;
queue<int> Queue;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	StudentVector = vector<pair<int, vector<int>>>(N + 1);

	while (M-->0)
	{
		cin >> A >> B;

		StudentVector[B].first++;
		StudentVector[A].second.push_back(B);
	}

	for (int i = 1; i < StudentVector.size(); ++i)
	{
		if (StudentVector[i].first == 0)
		{
			Queue.push(i);
		}
	}

	while (Queue.empty() == false)
	{
		int Current = Queue.front(); Queue.pop();

		cout << Current << ' ';

		for (int i = 0; i < StudentVector[Current].second.size(); ++i)
		{
			if (--StudentVector[StudentVector[Current].second[i]].first == 0)
			{
				Queue.push(StudentVector[Current].second[i]);
			}
		}
	}
	cout << '\n';

	return 0;
}