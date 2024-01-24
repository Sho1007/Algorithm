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

int V, E, Start, End, Cost;

vector<vector<int>> Board;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;

	Board = vector<vector<int>>(V + 1, vector<int>(V + 1, -1));

	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;

		Board[Start][End] = Cost;
	}

	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				if (Board[i][k] == -1 || Board[k][j] == -1) continue;
				if (Board[i][j] != -1 && Board[i][j] < Board[i][k] + Board[k][j]) continue;
				Board[i][j] = Board[i][k] + Board[k][j];
			}
		}
	}

	int Min = -1;

	for (int i = 1; i <= V; ++i)
	{
		if (Board[i][i] == -1) continue;

		if (Min == -1 || Min > Board[i][i]) Min = Board[i][i];
	}

	cout << Min << '\n';

	return 0;
}