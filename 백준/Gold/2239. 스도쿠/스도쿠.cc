#include <iostream>
#include <set>
using namespace std;

string Input;

int Board[9][9] = {};

bool Rows[9][10];
bool Columns[9][10];
bool Blocks[9][10];

int AnswerCount = 0;

void Print()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << Board[i][j];
		}
		cout << '\n';
	}
}

int CalcBlockIndex(int i, int j)
{
	return (i / 3) * 3 + (j / 3);
}

bool Solve(int Current)
{
	if (AnswerCount == 81) return true;

	int X = Current / 9;
	int Y = Current % 9;

	if (Board[X][Y] != 0) return Solve(Current + 1);

	for (int i = 1; i <= 9; ++i)
	{
		if (Rows[X][i] == false && Columns[Y][i] == false && Blocks[CalcBlockIndex(X, Y)][i] == false)
		{
			Rows[X][i] = true;
			Columns[Y][i] = true;
			Blocks[CalcBlockIndex(X, Y)][i] = true;

			Board[X][Y] = i;

			AnswerCount++;

			if (Solve(Current + 1)) return true;
			else
			{
				Rows[X][i] = false;
				Columns[Y][i] = false;
				Blocks[CalcBlockIndex(X, Y)][i] = false;

				Board[X][Y] = 0;

				AnswerCount--;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; ++i)
	{
		cin >> Input;

		for (int j = 0; j < 9; ++j)
		{
			Board[i][j] = Input[j] - '0';

			if (Board[i][j] != 0)
			{
				AnswerCount++;

				Rows[i][Board[i][j]] = true;
				Columns[j][Board[i][j]] = true;
				Blocks[CalcBlockIndex(i, j)][Board[i][j]] = true;
			}
		}
	}

	if (Solve(0))
	{
		Print();
	}

	return 0;
}