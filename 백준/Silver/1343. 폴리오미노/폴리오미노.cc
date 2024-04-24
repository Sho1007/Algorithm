#include <iostream>
#include <string>
using namespace std;

string String, Answer = "";

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> String;

    int XCount = 0;

    for (int i = 0; i < String.length(); ++i)
    {
        if (String[i] == '.')
        {
            if (XCount > 0)
            {
                if (XCount % 2 != 0)
                {
                    cout << "-1\n";
                    return 0;
                }

                for (int i = 0; i < XCount / 4; ++i)
                {
                    Answer += "AAAA";
                }

                if (XCount % 4 == 2)
                {
                    Answer += "BB";
                }

                XCount = 0;
            }
            Answer += '.';
        }
        else
        {
            XCount++;
        }
    }

    if (XCount > 0)
    {
        if (XCount % 2 != 0)
        {
            cout << "-1\n";
            return 0;
        }

        for (int i = 0; i < XCount / 4; ++i)
        {
            Answer += "AAAA";
        }

        if (XCount % 4 == 2)
        {
            Answer += "BB";
        }
        
    }

    cout << Answer << '\n';
    
    return 0;
}