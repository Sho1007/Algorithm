#include <iostream>
#include <queue>
using namespace std;

int TestCase;
int VertexCount;
int EdgeCount;

int Start, End;

vector<vector<int>> VertexVector;
vector<int> ColorVector;

bool BFS(int StartPos)
{
	ColorVector[StartPos] = 1;

	queue<int> Queue;
	Queue.push(StartPos);

	while (Queue.empty() == false)
	{
		int Current = Queue.front(); Queue.pop();

		for (int i = 0; i < VertexVector[Current].size(); ++i)
		{
			if (ColorVector[VertexVector[Current][i]] == 0)
			{
				// 아직 색깔이 칠해지지 않음

				ColorVector[VertexVector[Current][i]] = ColorVector[Current] == 1 ? 2 : 1;
				Queue.push(VertexVector[Current][i]);
			}
			else
			{
				// 이미 색깔이 있음
				if (ColorVector[VertexVector[Current][i]] == ColorVector[Current]) return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> TestCase;

	while (TestCase-->0)
	{
		cin >> VertexCount >> EdgeCount;

		VertexVector = vector<vector<int>>(VertexCount + 1);
		ColorVector = vector<int>(VertexCount + 1, 0);

		for (int i = 0; i < EdgeCount; ++i)
		{
			cin >> Start >> End;
			VertexVector[Start].push_back(End);
			VertexVector[End].push_back(Start);
		}

		bool bIsBipart = true;
		for (int i = 1; i <= VertexCount; ++i)
		{
			if (ColorVector[i] == 0)
			{
				if (BFS(i) == false)
				{
					bIsBipart = false;
					break;
				}
			}
		}

		if (bIsBipart) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}