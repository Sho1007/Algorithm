#include <iostream>
#include <string>
#include <stack>
using namespace std;

string String;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (true)
    {
        getline(cin, String);
        if (String.compare(".") == 0)
        {
            break;
        }

        stack<char> Stack;
        bool bIsBalanced = true;
        for (int i = 0; i < String.length(); ++i)
        {
            if (String[i] == '(' || String[i] == '[')
            {
                Stack.push(String[i]);
            }
            else if (String[i] == ')')
            {
                if (Stack.empty() || Stack.top() != '(')
                {
                    bIsBalanced = false;
                    break;
                }

                Stack.pop();
            }
            else if (String[i] == ']')
            {
                if (Stack.empty() || Stack.top() != '[')
                {
                    bIsBalanced = false;
                    break;
                }

                Stack.pop();
            }
        }

        if (bIsBalanced)
        {
            if (Stack.empty())
            {
                cout << "yes\n";
                continue;
            }
        }

        cout << "no\n";
    }
    
    return 0;
}