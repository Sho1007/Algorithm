#include <iostream>
#include <queue>
using namespace std;

struct COMP
{
	bool operator()(pair<pair<int, int>, int>& A, pair<pair<int, int>, int>& B)
	{
		return A.second > B.second;
	}
};

int N, M, A, B, C;

vector<int> Parent;
priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int, int>, int>>, COMP> PQ;

int FindParent(int Num)
{
	if (Parent[Num] == Num) return Num;

	return Parent[Num] = FindParent(Parent[Num]);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	Parent = vector<int>(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		Parent[i] = i;
	}

	while (M-->0)
	{
		cin >> A >> B >> C;
		PQ.push({ {A, B}, C });
	}

	int Result = 0;

	while (PQ.empty() == false)
	{
		auto Current = PQ.top(); PQ.pop();
		// cout << Current.first.first << " <-> " << Current.first.second << " : " << Current.second << '\n';

		A = Current.first.first;
		B = Current.first.second;

		int AParent = FindParent(A);
		int BParent = FindParent(B);

		if (AParent == BParent) continue;

		Parent[AParent] = BParent;

		Result += Current.second;
	}

	cout << Result << '\n';

	return 0;
}