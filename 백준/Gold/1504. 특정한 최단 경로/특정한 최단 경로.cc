#include <iostream>
using namespace std;

int V, E, Start, End, Cost, A, B;

int CostMatrix[801][801] = {};
int BeforeVertexMatrix[801][801] = {};

void PrintCost()
{
	cout << "Print : \n";
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 1; j <= V; ++j)
			cout << CostMatrix[i][j] << ' ';
		cout << '\n';
	}
}

void PrintBefore()
{
	cout << "Print : \n";
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 1; j <= V; ++j)
			cout << BeforeVertexMatrix[i][j] << ' ';
		cout << '\n';
	}
}

void FloydWarshall()
{
	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				if (CostMatrix[i][k] == -1 || CostMatrix[k][j] == -1) continue;
				if (CostMatrix[i][j] == -1 || CostMatrix[i][k] + CostMatrix[k][j] < CostMatrix[i][j])
				{
					CostMatrix[i][j] = CostMatrix[i][k] + CostMatrix[k][j];
					BeforeVertexMatrix[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;

	fill(CostMatrix[0], CostMatrix[800] + 801, -1);

	for (int i = 1; i <= V; ++i)
	{
		CostMatrix[i][i] = 0;
	}

	for (int i = 0; i < E; ++i)
	{
		cin >> Start >> End >> Cost;

		if (CostMatrix[Start][End] == -1 || CostMatrix[Start][End] > Cost)
		{
			CostMatrix[Start][End] = Cost;
			BeforeVertexMatrix[Start][End] = Start;
			CostMatrix[End][Start] = Cost;
			BeforeVertexMatrix[End][Start] = End;
		}
	}

	cin >> A >> B;

	FloydWarshall();

	/*PrintCost();
	PrintBefore();*/

	if (A != 1 && B != V)
	{
		int Current = A;
		bool FoundB = false;
		while (Current != 1 && Current != 0)
		{
			Current = BeforeVertexMatrix[1][Current];
			if (Current == B)
			{
				FoundB = true;
			}
			if (Current == -1)
			{
				FoundB = false;
				break;
			}
		}

		if (FoundB && CostMatrix[A][V] != -1)
		{
			cout << CostMatrix[1][A] + CostMatrix[A][V] << '\n';
			return 0;
		}

		Current = B;
		bool FoundA = false;
		while (Current != 1 && Current != 0)
		{
			Current = BeforeVertexMatrix[1][Current];
			if (Current == A)
			{
				FoundA = true;
			}
			if (Current == -1)
			{
				FoundA = false;
				break;
			}
		}

		if (FoundA && CostMatrix[B][V] != -1)
		{
			cout << CostMatrix[1][B] + CostMatrix[B][V] << '\n';
			return 0;
		}
	}

	int Result1, Result2;

	// A -> B
	if (CostMatrix[1][A] != -1 && CostMatrix[A][B] != -1 && CostMatrix[B][V] != -1)
	{
		Result1 = CostMatrix[1][A] + CostMatrix[A][B] + CostMatrix[B][V];
	}
	else
	{
		Result1 = -1;
	}

	// B -> A
	if (CostMatrix[1][B] != -1 && CostMatrix[B][A] != -1 && CostMatrix[A][V] != -1)
	{
		Result2 = CostMatrix[1][B] + CostMatrix[B][A] + CostMatrix[A][V];
	}
	else
	{
		Result2 = -1;
	}

	if (Result1 == -1 && Result2 == -1)
	{
		cout << -1 << '\n';
	}
	else
	{
		// Result1 != -1 || Result2 != -1

		if (Result1 == -1) cout << Result2 << '\n';
		else if (Result2 == -1) cout << Result1 << '\n';
		else
		{
			cout << (Result1 < Result2 ? Result1 : Result2) << '\n';
		}
	}

	/*PrintCost();
	PrintBefore();*/

	return 0;
}