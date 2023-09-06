#include <iostream>
using namespace std;

int Hour, Minute;

int CookTime;

int main()
{
    cin >> Hour >> Minute >> CookTime;

    Hour += CookTime / 60;

    Minute += CookTime % 60;

    if (Minute >= 60)
    {
        Hour++;
        Minute %= 60;
    }

    Hour %= 24;

    cout << Hour << ' ' << Minute << '\n';

    return 0;
}