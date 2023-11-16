#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, A, B;

vector<pair<int, vector<int>>> StudentVector;
vector<int> AnswerVector;
vector<bool> VisitVector;
queue<int> Queue;

void DFS(int Current)
{
	for (int i = 0; i < StudentVector[Current].second.size(); ++i)
	{
		if (VisitVector[StudentVector[Current].second[i]] == false)
		{
			VisitVector[StudentVector[Current].second[i]] = true;
			DFS(StudentVector[Current].second[i]);
		}
	}

	AnswerVector.push_back(Current);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	StudentVector = vector<pair<int, vector<int>>>(N + 1);
	VisitVector = vector<bool>(N + 1, false);

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

		DFS(Current);
	}

	reverse(AnswerVector.begin(), AnswerVector.end());

	for (int i = 0; i < AnswerVector.size(); ++i)
	{
		cout << AnswerVector[i] << ' ';
	}
	cout << '\n';

	return 0;
}