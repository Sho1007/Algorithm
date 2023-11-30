#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Vector;

void Merge(int Start, int Mid, int End)
{
	int Left = Start;
	int Right = Mid + 1;
	int Dest = 0;

	vector<int> Destination = vector<int>(End - Start + 1);

	while (Left <= Mid && Right <= End)
	{
		if (Vector[Left] <= Vector[Right])
		{
			Destination[Dest++] = Vector[Left++];
		}
		else
		{
			Destination[Dest++] = Vector[Right++];
		}
	}

	while (Left <= Mid)
	{
		Destination[Dest++] = Vector[Left++];
	}

	while (Right <= End)
	{
		Destination[Dest++] = Vector[Right++];
	}

	for (int i = 0; i < Destination.size(); ++i)
	{
		Vector[Start + i] = Destination[i];
	}
}

void MergeSort(int Start, int End)
{
	if (Start == End)
	{
		return;
	}

	int Mid = (Start + End) / 2;

	MergeSort(Start, Mid);
	MergeSort(Mid + 1, End);

	Merge(Start, Mid, End);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Vector = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Vector[i];
	}

	MergeSort(0, Vector.size() - 1);

	for (int i = 0; i < Vector.size(); ++i)
	{
		cout << Vector[i] << '\n';
	}

	return 0;
}