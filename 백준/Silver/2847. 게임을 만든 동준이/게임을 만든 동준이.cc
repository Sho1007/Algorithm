#include <iostream>
using namespace std;

int N;
int Array[100] = {};
int Answer = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    for (int i = N-2; i>=0; --i)
    {
        if (Array[i] >= Array[i+1])
        {
            Answer += Array[i] - (Array[i+1] - 1);
            Array[i] = Array[i+1] - 1;
        }
    }

    cout << Answer << '\n';
    
    return 0;
}