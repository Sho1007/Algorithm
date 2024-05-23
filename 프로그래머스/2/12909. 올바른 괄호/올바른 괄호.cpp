#include<string>
#include <iostream>

#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    if (s.length() % 2 != 0)
        return false;
    
    stack<char> bracketStack;
    
    for (int i = s.length()-1; i >= 0; --i)
    {
        // 여는 괄호 발견
        if (s[i] == '(')
        {
            if (bracketStack.size() > 0 && bracketStack.top() == ')')
                bracketStack.pop();
            else
                return false;
        }
        else if (s[i] == ')')
            bracketStack.push(s[i]);
    }
    
    

    return answer;
}