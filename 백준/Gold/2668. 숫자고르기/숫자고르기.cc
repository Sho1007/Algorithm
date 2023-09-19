    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Array[101];
vector<int> PickedNumber;
vector<int> Visited = vector<int>(101, false);


void Trace(vector<int>& TraceNumber, vector<bool>& VisitedArray, int StartNum)
{
	if (Array[TraceNumber.back()] == StartNum)
	{
		for (int i = 0; i < TraceNumber.size(); ++i)
		{
			PickedNumber.push_back(TraceNumber[i]);
			Visited[TraceNumber[i]] = true;
		}

		return;
	}
	else
	{
		if (VisitedArray[Array[TraceNumber.back()]] == true) return;
		else
		{
			TraceNumber.push_back(Array[TraceNumber.back()]);
			VisitedArray[TraceNumber.back()] = true;
			Trace(TraceNumber, VisitedArray, StartNum);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Array[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Visited[i]) continue;
		vector<int> TraceNumber;
		vector<bool> VisitedArray(101, false);
		TraceNumber.push_back(i);
		VisitedArray[i] = true;

		Trace(TraceNumber, VisitedArray, i);
	}

	sort(PickedNumber.begin(), PickedNumber.end());

	cout << PickedNumber.size() << '\n';

	for (int i = 0; i < PickedNumber.size(); ++i)
	{
		cout << PickedNumber[i] << '\n';
	}

	return 0;
}