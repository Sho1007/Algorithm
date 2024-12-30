#include <iostream>
#include <string>
using namespace std;

int N;

string StringArray[13] = {};
string ZeroString = " ";

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    StringArray[0] = "-";
    for (int i = 1; i <= 12; ++i)
    {
        StringArray[i] = StringArray[i-1] + ZeroString + StringArray[i-1];
        ZeroString = ZeroString + ZeroString + ZeroString;
    }
    
    while (cin >> N)
    {
        cout << StringArray[N] << '\n';
    }
    
    return 0;
}