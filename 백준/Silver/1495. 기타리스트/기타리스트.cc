#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M, S, Input, MinusVolume, PlusVolume;

set<int> CurrentVolume;

int main()
{
	cin >> N >> S >> M;

	CurrentVolume.insert(S);

	for (int i = 0; i < N; ++i)
	{
		cin >> Input;

		set<int> NewVolume;

		for (int Volume : CurrentVolume)
		{
			MinusVolume = Volume - Input;
			PlusVolume = Volume + Input;

			if (MinusVolume >= 0)
			{
				NewVolume.insert(MinusVolume);
			}
			if (PlusVolume <= M)
			{
				NewVolume.insert(PlusVolume);
			}
		}

		CurrentVolume = NewVolume;
	}

	if (CurrentVolume.empty())
	{
		cout << "-1\n";
	}
	else
	{
		cout << *CurrentVolume.rbegin() << '\n';
	}

	cout << '\n';

	return 0;
}