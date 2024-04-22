#include <iostream>
#include <algorithm>
using namespace std;

int N, X, Answer = 0;
int Array[100'000] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    cin >> X;

    sort(Array, Array + N);

    int Left = 0, Right = N - 1;

    while (Left < Right)
    {
        int Current = Array[Left] + Array[Right];
        if (Current > X)
        {
            Right--;
        }
        else if (Current < X)
        {
            Left++;
        }
        else if (Current == X)
        {
            Answer++;
            Right--;
        }
    }
    
    cout << Answer << '\n';
    
    return 0;
}