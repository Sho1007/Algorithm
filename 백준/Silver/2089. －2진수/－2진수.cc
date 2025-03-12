#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline int ABS(int A) { return A > 0 ? A : -A; }

int N;
bool IsNegative = false;
string Binary = "";

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    
    if (N == 0)
    {
        cout << "0\n";
        return 0;
    }
    
    while (ABS(N) > 0)
    {
        if (N % -2 == 0)
        {
            Binary += '0';
            N /= -2;
        }
        else
        {
            Binary += '1';
            N = (N - 1) / -2;
        }
    }

    reverse(Binary.begin(), Binary.end());
    cout << Binary << '\n';

    return 0;
}