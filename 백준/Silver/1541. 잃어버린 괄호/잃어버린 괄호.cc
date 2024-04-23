#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;

    cin >> s;

    string num;
    int answer = 0;
    int sum = 0;
    int minusSum = 0;
    int sign = 1;
    int n;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            num += s[i];
        }
        else
        {
            n = stoi(num);
            num = "";

            if (sign == 1)
            {
                answer += n;
            }
            // sign == -1
            else
            {
                sum += n;
            }

            if (s[i] == '-')
            {
                sign = -1;
                answer -= sum;
                sum = 0;
            }
        }
    }
    n = stoi(num);
    if (sign == -1)
    {
        sum += n;
        answer -= sum;
    }
    else
    {
        answer += n;
    }

    cout << answer << endl;

    return 0;
}