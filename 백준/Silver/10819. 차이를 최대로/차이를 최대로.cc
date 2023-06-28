#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Array;
vector<int> ResultArray;

int MaxNum = -1;

void Calc()
{
	int Sum = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		int Result = ResultArray[i] - ResultArray[i + 1];
		Sum += Result > 0 ? Result : -Result;
	}

	MaxNum = MaxNum > Sum ? MaxNum : Sum;
}

void BackTracking()
{
	if (ResultArray.size() == N)
	{
		Calc();
		return;
	}

	for (int i = 0; i < Array.size(); ++i)
	{
		ResultArray.push_back(Array[i]);
		Array.erase(Array.begin() + i);
		BackTracking();
		Array.insert(Array.begin() + i, ResultArray.back());
		ResultArray.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Array = vector<int>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> Array[i];
	}
	BackTracking();

	cout << MaxNum << '\n';

	return 0;
}