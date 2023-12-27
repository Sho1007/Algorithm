#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Input;
vector<int> Vector;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Input;

		if (Vector.empty() || Vector.back() < Input)
		{
			Vector.push_back(Input);
		}
		else
		{
			auto Iter = lower_bound(Vector.begin(), Vector.end(), Input);
			int Index = Iter - Vector.begin();
			Vector[Index] = Input;
		}
	}

	cout << N - Vector.size() << '\n';

	return 0;
}