#include <iostream>
#include <algorithm>
using namespace std;

inline int ABS(int A) { return A > 0 ? A : -A; }

int N;

int Array[100'000] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    sort(Array, Array + N);

    int Min = 2'000'000'000;
    int MinLeft, MinRight;
    int Left = 0, Right = N - 1;
    

    while (Left < Right)
    {
        int Current = Array[Left] + Array[Right];

        if (ABS(Current) < Min)
        {
            Min = ABS(Current);
            MinLeft = Left;
            MinRight = Right;

            if (Min == 0) break;
        }

        if (Current < 0)
        {
            Left++;
        }
        else if (Current > 0)
        {
            Right--;
        }
    }

    cout << Array[MinLeft] << ' ' << Array[MinRight] << '\n';
    
    return 0;
}