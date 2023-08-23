#include <iostream>
using namespace std;

int ATop, ABottom, BTop, BBottom;
int Top, Bottom;

int GetGCD(int A, int B)
{
    int Temp, N;

    if (A < B)
    {
        Temp = A;
        A = B;
        B = Temp;
    }

    while (B != 0)
    {
        N = A % B;
        A = B;
        B = N;
    }

    return A;
}

int main()
{
    cin >> ATop >> ABottom >> BTop >> BBottom;

    Bottom = ABottom * BBottom;

    Top = (ATop * BBottom) + (BTop * ABottom);

    int GCD = GetGCD(Top, Bottom);

    cout << Top / GCD << ' ' << Bottom / GCD << '\n';

    return 0;
}