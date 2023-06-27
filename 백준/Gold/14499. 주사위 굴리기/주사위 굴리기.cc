#include <iostream>
using namespace std;

typedef struct FPoint
{
public:
	int X, Y;
} FPoint;

FPoint BoardSize;
FPoint DicePos;
int** Board;
int OrderCount;
int OrderDirection;

bool bIsDebug;

int Left, Right, Front, Back, Top, Bottom;

void PrintBoard()
{
	cout << "PrintBoard ----------------\n";
	for (int i = 0; i < BoardSize.Y; ++i)
	{
		for (int j = 0; j < BoardSize.X; ++j)
		{
			if (DicePos.Y == i && DicePos.X == j) cout << "* ";
			else cout << Board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void PrintDice()
{
	cout << "PrintDice " << DicePos.X << ", " << DicePos.Y << "----------------\n";
	cout << "  " << Front << '\n';
	cout << Left << ' ' << Top << ' ' << Right << '\n';
	cout << "  " << Back << '\n';
	cout << "  " << Bottom << '\n';

}

void RollDice(int Direction)
{
	int TempBottom = Board[DicePos.Y][DicePos.X];
	bool bIsMoved = false;
	switch (Direction)
	{
	case 1:
		// East
		if (bIsDebug) cout << "East\n";
		if (DicePos.X < BoardSize.X - 1)
		{
			bIsMoved = true;
			DicePos.X++;
			TempBottom = Right;
			Right = Top;
			Top = Left;
			Left = Bottom;
		}
		break;
	case 2:
		// West
		if (bIsDebug) cout << "West\n";
		if (DicePos.X > 0)
		{
			bIsMoved = true;
			DicePos.X--;
			TempBottom = Left;
			Left = Top;
			Top = Right;
			Right = Bottom;
		}
		break;
	case 3:
		// North
		if (bIsDebug) cout << "North\n";
		if (DicePos.Y > 0)
		{
			bIsMoved = true;
			DicePos.Y--;
			TempBottom = Front;
			Front = Top;
			Top = Back;
			Back = Bottom;
		}
		break;
	case 4:
		// South
		if (bIsDebug) cout << "South\n";
		if (DicePos.Y < BoardSize.Y - 1)
		{
			bIsMoved = true;
			DicePos.Y++;
			TempBottom = Back;
			Back = Top;
			Top = Front;
			Front = Bottom;
		}
		break;
	}
	if (bIsMoved)
	{
		if (Board[DicePos.Y][DicePos.X] == 0)
		{
			Board[DicePos.Y][DicePos.X] = TempBottom;
			Bottom = Board[DicePos.Y][DicePos.X];
		}
		else
		{
			Bottom = Board[DicePos.Y][DicePos.X];
			Board[DicePos.Y][DicePos.X] = 0;
		}
		
		if (bIsDebug) cout << "Top : " << Top << '\n';
		else cout << Top << '\n';
	}
}

int main()
{
	bIsDebug = false;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> BoardSize.Y >> BoardSize.X >> DicePos.Y >> DicePos.X >> OrderCount;

	Left = Right = Front = Back = Top = Bottom = 0;

	Board = new int* [BoardSize.Y];

	for (int i = 0; i < BoardSize.Y; ++i)
	{
		Board[i] = new int[BoardSize.X];
		for (int j = 0; j < BoardSize.X; ++j)
		{
			cin >> Board[i][j];
		}
	}

	if (bIsDebug) PrintBoard();
	if (bIsDebug) PrintDice();

	for (int i = 0; i < OrderCount; ++i)
	{
		cin >> OrderDirection;
		RollDice(OrderDirection);
		if (bIsDebug) PrintBoard();
		if (bIsDebug) PrintDice();
	}

	for (int i = 0; i < BoardSize.Y; ++i)
	{
		delete[] Board[i];
	}

	delete[] Board;

	return 0;
}