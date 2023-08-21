#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Str, Substr = "";
bool bIsTag = false;
int StartPos;

int main()
{
    getline(cin, Str);  

    for (int i = 0; i < Str.length(); ++i)
    {
        if (bIsTag)
        {
            // Find Untag Sign
            if (Str[i] == '>')
            {
                bIsTag = false;
            }
        }
        else
        {
            if (Str[i] == '<' || Str[i] == ' ')
            {
                if (Str[i] == '<')
                {
                    bIsTag = true;
                }

                if (Substr.length() > 0)
                {
                    reverse(Substr.begin(), Substr.end());
                    Str.replace(StartPos, Substr.length(), Substr);
                    Substr = "";
                }
            }
            else
            {
                if (Substr.length() == 0)
                {
                    StartPos = i;
                }
                Substr += Str[i];

                if (i == Str.length() - 1)
                {
                    reverse(Substr.begin(), Substr.end());
                    Str.replace(StartPos, Substr.length(), Substr);
                    Substr = "";
                }
            }

        }
    }

    cout << Str << '\n';

    return 0;
}