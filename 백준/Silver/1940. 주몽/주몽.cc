#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int Array[15'000] = {};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    sort(Array, Array + N);

    int Left = 0, Right = N -1, Answer = 0;
    
    while (Left < Right)
    {
        int Current = Array[Left] + Array[Right];

        if (Current == M)
        {
            Answer++;
            Right--;
        }
        else if (Current < M)
        {
            Left++;
        }
        else if (Current > M)
        {
            Right--;
        }
    }

    cout << Answer << '\n';
    
    return 0;
}