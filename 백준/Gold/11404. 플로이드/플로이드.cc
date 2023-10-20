#include <iostream>
#include <vector>
using namespace std;

inline int Min(int A, int B) { return A < B ? A : B; }

vector<vector<long long>> CostVector;
int N, M;
int Start, End, Cost;

// 노선은 하나가 아닐 수 있다 -> 입력 시 최소값 갱신

void PrintCost()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << CostVector[i][j] << ' ';
		}
		cout << '\n';
	}
}

void FW()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j || CostVector[i][k] == 0 || CostVector[k][j] == 0) continue;

				if (CostVector[i][j] == 0 || CostVector[i][j] > CostVector[i][k] + CostVector[k][j])
				{
					//cout << i << " -> " << k << " -> " << j << '\n';
					CostVector[i][j] = CostVector[i][k] + CostVector[k][j];

					//PrintCost();
				}
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	CostVector = vector<vector<long long>>(N + 1, vector<long long>(N + 1, 0));

	while (M-->0)
	{
		cin >> Start >> End >> Cost;
		if (CostVector[Start][End]) CostVector[Start][End] = Min(CostVector[Start][End], Cost);
		else CostVector[Start][End] = Cost;
	}

	FW();

	PrintCost();

	return 0;
}