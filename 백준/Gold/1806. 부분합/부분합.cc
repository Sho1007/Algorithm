#include <iostream>
#define MAX 987'654'321
using namespace std;

int N, S, Left = 0, Right = 0, Sum = 0;

int Answer = MAX;
int Array[100'000] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    Sum = Array[0]; 

    while (Left < N && Right < N)
    {
        if (Right < Left)
        {
            Right = Left;
            Sum = Array[Right];
        }
        
        if (Sum < S)
        {
            if (++Right >= N) break;
            Sum += Array[Right];
        }
        else
        {
            int Current = Right - Left + 1;
            if (Current < Answer)
            {
                Answer = Current;
            }

            Sum -= Array[Left++];
        }
    }

    if (Answer == MAX) cout << 0 << '\n';
    else cout << Answer << '\n';
    
    return 0;
}