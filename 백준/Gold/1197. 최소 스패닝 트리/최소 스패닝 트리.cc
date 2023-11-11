#include <iostream>
#include <queue>
using namespace std;

struct COMP
{
	bool operator()(pair<int,int>& A, pair<int,int>& B)
	{
		return A.second > B.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, COMP> PQ;

int V, E, Start, End, Cost, Answer = 0;
vector<vector<pair<int, int>>> EdgeVector;
bool Visited[10'001]{0, };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;

	EdgeVector = vector<vector<pair<int, int>>>(V + 1);

	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;
		EdgeVector[Start].push_back({ End, Cost });
		EdgeVector[End].push_back({ Start, Cost });
	}


	PQ.push({1, 0});

	while (PQ.empty() == false)
	{
		pair<int,int> Current = PQ.top(); PQ.pop();
		if (Visited[Current.first] == true) continue;

		//cout << Current.first << " : " << Current.second << '\n';
		Visited[Current.first] = true;
		Answer += Current.second;

		for (int i = 0; i < EdgeVector[Current.first].size(); ++i)
		{
			if (Visited[EdgeVector[Current.first][i].first] == true) continue;
			PQ.push(EdgeVector[Current.first][i]);
		}
	}

	cout << Answer << '\n';

	return 0;
}