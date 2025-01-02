#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, Input, Current = 1;
stack<int> Stack;
string Answer = "";

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Input;

		if (Input >= Current)
		{
			for (; Current <= Input; ++Current)
			{
				Answer += "+\n";
				Stack.push(Current);
			}

			Stack.pop();
			Answer += "-\n";
		}
		else if (Stack.empty() == false && Stack.top() == Input)
		{
			Stack.pop();
			Answer += "-\n";
		}
		else
		{
			Answer = "NO\n";
			break;
		}
	}

	cout << Answer << '\n';

	return 0;
}