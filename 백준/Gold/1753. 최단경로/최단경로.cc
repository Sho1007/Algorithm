#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E, K;

int Start, End, Cost;

vector<int> CostVector;

struct Comp
{
	bool operator()(pair<int, int>& A, pair<int, int>& B)
	{
		return A.second > B.second;
	}
};

vector<vector<pair<int, int>>> Verticies;

priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> EdgeQueue;

int main()
{
	cin >> V >> E >> K;
	CostVector = vector<int>(V + 1, -1);
	Verticies = vector<vector<pair<int, int>>>(V + 1);

	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;

		Verticies[Start].push_back({ End, Cost });
	}

	EdgeQueue.push({ K, 0 });

	while (!EdgeQueue.empty())
	{
		pair<int, int> Current = EdgeQueue.top(); EdgeQueue.pop();
		End = Current.first;
		Cost = Current.second;

		if (CostVector[End] == -1 || CostVector[End] > Cost)
		{
			CostVector[End] = Cost;

			for (int i = 0; i < Verticies[End].size(); ++i)
			{
				EdgeQueue.push({ Verticies[End][i].first,  Cost + Verticies[End][i].second});
			}
		}
	}

	for (int i = 1; i < CostVector.size(); ++i)
	{
		if (CostVector[i] == -1) cout << "INF\n";
		else cout << CostVector[i] << '\n';
	}

	return 0;
}