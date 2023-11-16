#include <iostream>
#include <string>
using namespace std;

string Source;
string Target;

int Answer = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	getline(cin, Source);
	getline(cin, Target);

	for (int i = 0; i < Source.size(); ++i)
	{
		bool bIsSame = true;
		for (int j = 0; j < Target.size(); ++j)
		{
			if (i + j >= Source.size() || Source[i + j] != Target[j])
			{
				bIsSame = false;
				break;
			}
		}

		if (bIsSame)
		{
			Answer++;
			i += Target.size() - 1;
		}
	}

	cout << Answer << '\n';

	return 0;
}