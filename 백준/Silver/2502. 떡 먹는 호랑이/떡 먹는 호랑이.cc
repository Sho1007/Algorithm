#include <iostream>
using namespace std;

int D, K;
int ACount[31] = {};
int BCount[31] = {};

int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);


    ACount[1] = 1;
    ACount[2] = 0;
    ACount[3] = 1;
    for (int i = 4; i < 31; ++i)
    {
        ACount[i] = ACount[i - 1] + ACount[i - 2];
    }

    BCount[2] = 1;
    for (int i = 3; i < 31; ++i)
    {
        BCount[i] = BCount[i - 1] + BCount[i - 2];
    }

    cin >> D >> K;

    for (int i = 1; i <= K; ++i)
    {
        int TotalB = K - (i * ACount[D]);
        if (TotalB % BCount[D] == 0)
        {
            cout << i << '\n';
            cout << (TotalB / BCount[D]) << '\n';
            break;
        }
    }

    return 0;
}