#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int Array[10'000];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    sort(Array, Array + N);

    for (int i = 0; i < N; ++i)
    {
        if (Array[i] <= L)
        {
            L++;
        }
        else
        {
            break;
        }
    }

    cout << L << '\n';
    
    return 0;
}