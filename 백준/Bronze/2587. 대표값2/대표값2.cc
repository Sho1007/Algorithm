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

void BubbleSort(vector<int>& Target)
{
	for (int i = Target.size()-1; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (Target[j-1] > Target[j])
			{
				int Temp = Target[j];
				Target[j] = Target[j - 1];
				Target[j - 1] = Temp;
			}

			//Print(Target);
		}
	}
}

vector<int> Vector;

int Input;
int Sum = 0;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		cin >> Input;
		Sum += Input;
		Vector.push_back(Input);
	}

	BubbleSort(Vector);

	cout << Sum / 5 << '\n';
	cout << Vector[2] << '\n';

	return 0;
}