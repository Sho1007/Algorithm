#include <iostream>
#include <queue>
#define INF 987'654'321
using namespace std;


struct COMP
{
	bool operator()(pair<int,int>& A, pair<int,int>& B)
	{
		return A.second > B.second;
	}
};

int V, E, K, Start, End, Cost;
vector<vector<pair<int, int>>> EdgeVector;
priority_queue<pair<int, int>, vector<pair<int, int>>, COMP> PQ;
vector<int> CostVector;

void Dijkstra()
{
	PQ.push({ K, 0 });

	while (PQ.empty() == false)
	{
		pair<int, int> Current = PQ.top(); PQ.pop();

		if (CostVector[Current.first] < Current.second) continue;
		CostVector[Current.first] = Current.second;

		for (int i = 0; i < EdgeVector[Current.first].size(); ++i)
		{
			if (CostVector[EdgeVector[Current.first][i].first] > Current.second + EdgeVector[Current.first][i].second)
			{
				PQ.push({ EdgeVector[Current.first][i].first, Current.second + EdgeVector[Current.first][i].second });
			}
		}
	}
}

void Print()
{
	for (int i = 1; i < CostVector.size(); ++i)
	{
		if (CostVector[i] == INF) cout << "INF\n";
		else cout << CostVector[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;

	EdgeVector = vector<vector<pair<int, int>>>(V + 1);
	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;
		EdgeVector[Start].push_back({End, Cost});
	}

	CostVector = vector<int>(V + 1, INF);

	Dijkstra();
	Print();

	return 0;
}