#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Print(vector<int>& Target)
{
	for (int i = 0; i < Target.size(); ++i)
	{
		cout << Target[i] << '\n';
	}
}

void QuickSort(vector<int>& Target)
{
	queue<pair<int, int>> Q;

	Q.push({ 0, Target.size() -1 });

	while (Q.empty() == false)
	{
		pair<int, int> Current = Q.front(); Q.pop();

		if (Current.first == Current.second) continue;

		int Left = Current.first + 1;
		int Right = Current.second;

		while (Left < Right)
		{
			while (Left < Target.size() && Target[Left] < Target[Current.first]) Left++;

			while (Right >=  0 && Target[Right] > Target[Current.first]) Right--;

			if (Left > Right) break;

			int Temp = Target[Left];
			Target[Left] = Target[Right];
			Target[Right] = Temp;
		}

		if (Target[Right] < Target[Current.first])
		{
			int Temp = Target[Current.first];
			Target[Current.first] = Target[Right];
			Target[Right] = Temp;
		}


		if (Current.first < Right - 1)
		{
			Q.push({ Current.first, Right - 1 });
		}
		if (Right + 1 < Current.second)
		{
			Q.push({ Right + 1, Current.second });
		}
	}
}

vector<int> Vector;

int N;
int Input;
int ZeroLeft, ZeroRight;
int MaxWeight = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	Vector = vector<int>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Vector[i];
	}
	QuickSort(Vector);
	Print(Vector);
	
	return 0;
}