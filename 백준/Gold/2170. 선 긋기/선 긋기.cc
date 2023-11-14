#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Start, End, Answer = 0;
vector<pair<int, int>> DotVector;
vector<pair<int, int>> AnswerVector;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	DotVector = vector<pair<int, int>>(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> DotVector[i].first >> DotVector[i].second;
	}

	sort(DotVector.begin(), DotVector.end(), [](pair<int, int>& A, pair<int, int>& B)->bool
		{
			if (A.first == B.first) return A.second < B.second;
			return A.first < B.first;
		});

	for (int i = 0; i < DotVector.size();)
	{
		AnswerVector.push_back(DotVector[i]);
		int j;
		for (j = i + 1; j < DotVector.size(); ++j)
		{
			if (AnswerVector.back().second < DotVector[j].first) break;

			if (AnswerVector.back().second < DotVector[j].second)
			{
				AnswerVector.back().second = DotVector[j].second;
			}
		}

		i = j;
	}

	for (int i = 0; i < AnswerVector.size(); ++i)
	{
		Answer += (AnswerVector[i].second - AnswerVector[i].first);
	}
	cout << Answer << '\n';

	return 0;
}