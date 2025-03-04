#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> TreeCountMap;
int TotalTreeCount = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed;
	cout.precision(4);

	string Input;
	while (true)
	{
		getline(cin, Input);
		if (cin.eof() == 1) break;

		TotalTreeCount++;
		TreeCountMap[Input]++;
	}

	for (auto Iter : TreeCountMap)
	{
		cout << Iter.first << ' ' << (Iter.second / (float)TotalTreeCount) * 100.f << '\n';
	}

	return 0;
}