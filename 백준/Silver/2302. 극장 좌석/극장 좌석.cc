#include <iostream>
#include <vector>
using namespace std;

int N, M, Input;
vector<int> VIP;
vector<unsigned int> Fibonacci;

int main()
{
	int Index = 3;

	Fibonacci.push_back(0);
	Fibonacci.push_back(1);
	Fibonacci.push_back(1);

	while (true)
	{
		Fibonacci.push_back(Fibonacci[Index - 1] + Fibonacci[Index - 2]);

		// cout << Index << " : " << Fibonacci[Index] << '\n';
		if (Fibonacci[Index] >= 2'000'000'000)
		{
			break;
		}
		Index++;
	}

	cin >> N >> M;

	int Current = 1;
	unsigned int Result = 1;

	while (M-->0)
	{
		cin >> Input;

		int Distance = Input - Current;
		if (Distance > 0)
		{
			Result *= (Fibonacci[Distance] + Fibonacci[Distance - 1]);
		}
		Current = Input + 1;
	}

	if (Current <= N)
	{
		int Distance = (N - Current) + 1;
		Result *= (Fibonacci[Distance] + Fibonacci[Distance - 1]);
	}

	cout << Result << '\n';
	

	return 0;
}