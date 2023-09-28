#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int>& Target)
{
	for (int i = 0; i < Target.size(); ++i)
	{
		cout << Target[i] << ' ';
	}
	cout << '\n';
}

void InsertionSort(vector<int>& Target)
{
	if (Target.size() == 1) return;

	for (int i = 1; i < Target.size(); ++i)
	{
		if (Target[i] < Target[i - 1])
		{
			int Data = Target[i];
			Target.erase(Target.begin() + i);
			for (int j = 0; j < i; ++j)
			{
				if (Data < Target[j])
				{
					Target.insert(Target.begin() + j, Data);
					break;
				}
			}
		}

		//Print(Target);
	}
}

vector<int> Vector;

int N, K;
int Input;

int main()
{
	cin >> N >> K;
	Vector = vector<int>(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Vector[i];
	}

	InsertionSort(Vector);


	cout << Vector[Vector.size() - K] << '\n';

	return 0;
}