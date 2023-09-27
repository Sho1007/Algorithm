#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

/*
*	5397 - 키로거
*	문자열에서 명령들 (< 왼쪽이동, > 오른쪽이동, - 앞 문자 제거) 를 처리해서 결과값 도출
*	1. 삽입은 앞에 일어난다
*	2. 삭제도 앞에 일어난다.
*/
int T, Pos;

string Source;
string Target;

stack<int> FrontStack, BackStack;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;

	while (T-- > 0)
	{
		cin >> Source;
		Target = "";
		for (int i = 0; i < Source.size(); ++i)
		{
			if (Source[i] == '<')
			{
				if (!FrontStack.empty())
				{
					BackStack.push(FrontStack.top());
					FrontStack.pop();
				}
			}
			else if (Source[i] == '>')
			{
				if (!BackStack.empty())
				{
					FrontStack.push(BackStack.top());
					BackStack.pop();
				}
			}
			else if (Source[i] == '-')
			{
				if (!FrontStack.empty()) FrontStack.pop();
			}
			else
			{
				FrontStack.push(Source[i]);
			}
		}
		while (!FrontStack.empty())
		{
			Target += FrontStack.top();
			FrontStack.pop();
		}

		reverse(Target.begin(), Target.end());

		while (!BackStack.empty())
		{
			Target += BackStack.top();
			BackStack.pop();
		}

		cout << Target << '\n';
	}

	return 0;
}