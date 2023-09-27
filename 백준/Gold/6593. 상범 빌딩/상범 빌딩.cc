#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 탈출 -> 경로 찾기 -> DFS? BFS?
// 그런데 보통의 경로찾기는 2차원인 반면, 얘는 3차원이라는 점을 유의

int dX[6] = {0, 0, 0, 0, -1, 1};
int dY[6] = {0, 0, -1, 1, 0, 0};
int dFloor[6] = { -1, 1, 0, 0, 0, 0 };

typedef struct Location
{
	int X, Y, Floor;

	Location(int NewFloor = 0, int NewY = 0, int NewX = 0) : X(NewX), Y(NewY), Floor(NewFloor) {}
};

int C, L, R;
vector<vector<vector<char>>> Board;
vector<vector<vector<int>>> VisitCost;
Location Start;
Location End;

bool operator==(Location& A, Location& B)
{
	return (A.X == B.X) && (A.Y == B.Y) && (A.Floor == B.Floor);
}

void PrintBoard()
{
	for (int i = 0; i < Board.size(); ++i)
	{
		for (int j = 0; j < Board[i].size(); ++j)
		{
			for (int k = 0; k < Board[i][j].size(); ++k)
			{
				cout << Board[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void PrintVisitCost()
{
	for (int i = 0; i < Board.size(); ++i)
	{
		for (int j = 0; j < Board[i].size(); ++j)
		{
			for (int k = 0; k < Board[i][j].size(); ++k)
			{
				cout << VisitCost[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void FindPath()
{
	queue<Location> Q;

	Q.push(Start);

	while (Q.empty() == false)
	{
		Location Current = Q.front(); Q.pop();
		Location Next;
		for (int i = 0; i < 6; ++i)
		{
			Next.Floor = Current.Floor + dFloor[i];
			Next.Y = Current.Y + dY[i];
			Next.X = Current.X + dX[i];

			if (Next.Floor < 0 || Next.Floor >= L || Next.Y < 0 || Next.Y >= R || Next.X < 0 || Next.X >= C) continue;
			if (Next == Start) continue;
			if (Board[Next.Floor][Next.Y][Next.X] == '#') continue;
			if (VisitCost[Next.Floor][Next.Y][Next.X] != 0 && VisitCost[Next.Floor][Next.Y][Next.X] <= VisitCost[Current.Floor][Current.Y][Current.X] + 1) continue;

			VisitCost[Next.Floor][Next.Y][Next.X] = VisitCost[Current.Floor][Current.Y][Current.X] + 1;
			Q.push(Next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> L >> R >> C;
		if (C == L && L == R && R == 0) break;

		Board = vector<vector<vector<char>>>(L, vector<vector<char>>(R, vector<char>(C)));
		VisitCost = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C, 0)));

		for (int i = 0; i < Board.size(); ++i)
		{
			for (int j = 0; j < Board[i].size(); ++j)
			{
				for (int k = 0; k < Board[i][j].size(); ++k)
				{
					cin >> Board[i][j][k];
					if (Board[i][j][k] == 'S')
					{
						Start = Location(i, j, k);
					}
					else if (Board[i][j][k] == 'E')
					{
						End = Location(i, j, k);
					}
					else if (Board[i][j][k] == '#')
					{
						VisitCost[i][j][k] = -1;
					}
				}
			}
		}

		FindPath();

		if (VisitCost[End.Floor][End.Y][End.X] == 0)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in " << VisitCost[End.Floor][End.Y][End.X] << " minute(s).\n";
		}

		Board.clear();
		VisitCost.clear();
	}
	

	return 0;
}