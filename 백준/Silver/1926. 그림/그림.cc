#include <iostream>
using namespace std;

int Height, Width;

bool Board[501][501] = {};
bool Visited[501][501] = {};
int PaintingCount = 0, MaxSize = 0, NewSize;
int DX[4] = {0, 0, -1, 1};
int DY[4] = {-1, 1, 0, 0};

int Find(int Y, int X)
{
	Visited[Y][X] = true;
	int Size = 1;

	for (int i = 0; i < 4; ++i)
	{
		int NextY = DY[i] + Y;
		int NextX = DX[i] + X;

		if (NextY < 1 || NextY > Height || NextX < 1 || NextX > Width) continue;

		if (Visited[NextY][NextX] == false && Board[NextY][NextX] == 1) Size += Find(NextY, NextX);
	}

	return Size;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> Height >> Width;

	for (int i = 1; i <= Height; ++i)
	{
		for (int j = 1; j <= Width; ++j)
		{
			cin >> Board[i][j];
		}
	}

	for (int i = 1; i <= Height; ++i)
	{
		for (int j = 1; j <= Width; ++j)
		{
			if (Board[i][j] == 1 && Visited[i][j] == false)
			{
				PaintingCount++;
				NewSize = Find(i, j);
				MaxSize = MaxSize > NewSize ? MaxSize : NewSize;
			}
		}
	}

	cout << PaintingCount << '\n';
	cout << MaxSize << '\n';

	return 0;
}