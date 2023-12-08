#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int ASize, BSize;
vector<int> A, B;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;

	while (T-->0)
	{
		cin >> ASize >> BSize;
		A.clear(); B.clear();
		A = vector<int>(ASize);
		B = vector<int>(BSize);

		for (int i = 0; i < ASize; ++i)
		{
			cin >> A[i];
		}

		for (int i = 0; i < BSize; ++i)
		{
			cin >> B[i];
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int Result = 0;

		for (int i = 0; i < A.size(); ++i)
		{
			Result += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
		}

		cout << Result << '\n';
	}

	return 0;
}