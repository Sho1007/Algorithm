#include <iostream>
#include <string>
using namespace std;

int L, R, Answer = 0;
string LString, RString;

int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> L >> R;
    LString = to_string(L);
    RString = to_string(R);

    string ZeroString = string(RString.length() - LString.length(), '0');
    LString = ZeroString + LString;

    // cout << LString << ' ' << RString << '\n';

    for (int i = 0; i < LString.length(); ++i)
    {
        if (LString[i] != RString[i])
        {
            break;
        }

        if (LString[i] == '8')
        {
            Answer++;
        }
    }

    cout << Answer << '\n';

    return 0;
}