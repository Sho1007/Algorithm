#include <iostream>
#include <vector>
using namespace std;

int N;
int Board[11][11] = {};

vector<int> CountryArray;
vector<int> CurrentArray;

int MinCost = -1;
int CurrentCost = 0;
void BT()
{
	if (CountryArray.empty())
	{
		if (Board[CurrentArray.back()][CurrentArray.front()] == 0) return;
		
		int FinalCost = CurrentCost + Board[CurrentArray.back()][CurrentArray.front()];

		if (MinCost == -1 || MinCost > FinalCost) MinCost = FinalCost;
		return;
	}
	for (int i = 0; i < CountryArray.size(); ++i)
	{
		if (CurrentArray.empty() || (Board[CurrentArray.back()][CountryArray[i]] > 0))
		{
			if (!CurrentArray.empty())
			{
				CurrentCost += Board[CurrentArray.back()][CountryArray[i]];
			}
			CurrentArray.push_back(CountryArray[i]);
			CountryArray.erase(CountryArray.begin() + i);
			BT();
			CountryArray.insert(CountryArray.begin() + i, CurrentArray.back());
			CurrentArray.pop_back();
			if (!CurrentArray.empty())
			{
				CurrentCost -= Board[CurrentArray.back()][CountryArray[i]];
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		CountryArray.push_back(i);
		for (int j = 1; j <= N; ++j)
		{
			cin >> Board[i][j];
		}
	}

	BT();

	cout << MinCost << '\n';

	return 0;
}