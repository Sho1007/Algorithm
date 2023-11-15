#include <iostream>
#include <queue>
using namespace std;

int N, K, S, Y, X;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
vector<vector<int>> Board;

struct COMP
{
	bool operator()(pair<int, pair<int, int>>& A, pair<int, pair<int, int>>& B)
	{
		return A.first > B.first;
	}
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, COMP> PQ;

void Print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	Board = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Board[i][j];
			if (Board[i][j] != 0)
			{
				PQ.push({ Board[i][j], {i, j} });
			}
		}
	}

	cin >> S >> Y >> X;

	int Time = 0;

	while (Time++ < S)
	{
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, COMP> NewPQ;
		while (PQ.empty() == false)
		{
			int Virus = PQ.top().first;
			pair<int, int> Pos = PQ.top().second;
			PQ.pop();
			

			for (int i = 0; i < 4; ++i)
			{
				int NextY = Pos.first + dy[i];
				int NextX = Pos.second + dx[i];

				if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;
				if (Board[NextY][NextX] != 0) continue;

				Board[NextY][NextX] = Virus;
				NewPQ.push({ Virus, {NextY, NextX} });
			}
		}

		//Print();

		PQ = NewPQ;
		if (PQ.empty()) break;
	}

	cout << Board[Y - 1][X - 1] << '\n';

	return 0;
}