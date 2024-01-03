#include <iostream>
#include <vector>
using namespace std;

int N, X, Y, D, G, Answer = 0;

bool Board[101][101] = {};

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

void Check()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (Board[i][j] == true)
			{
				if (Board[i+1][j] && Board[i][j+1] && Board[i+1][j+1])
				{
					Answer++;
				}
			}
		}
	}

	cout << Answer << '\n';
}

void AddGeneration(vector<int>& DirVec, int CurrentGeneration)
{
	if (G == CurrentGeneration) return;

	for (int i = DirVec.size() - 1; i >= 0; --i)
	{
		DirVec.push_back((DirVec[i] + 1) % 4);
	}

	AddGeneration(DirVec, CurrentGeneration + 1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> X >> Y >> D >> G;

		vector<int> DirVec;
		DirVec.push_back(D);

		AddGeneration(DirVec, 0);

		Board[Y][X] = true;

		for (int i = 0; i < DirVec.size(); ++i)
		{
			Y += dy[DirVec[i]];
			X += dx[DirVec[i]];

			if (X < 0 || X > 100 || Y < 0 || Y > 100) continue;

			Board[Y][X] = true;
		}
	}

	Check();

	return 0;
}