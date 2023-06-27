#pragma GCC optimize("Ofast")
#include <iostream>
using namespace std;

int N , M, Sum, Result = 0;
int* Array;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    Array = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }
    
    for (int i = 0; i < N; ++i)
    {
        Sum = 0;
        for (int j = i; j < N; ++j)
        {
            Sum += Array[j];
            if (Sum == M)
            {
                Result++;
                break;
            } else if (Sum > M) break;
        }
    }
    
    cout << Result << '\n';
    
    delete[] Array;
    
    return 0;
}