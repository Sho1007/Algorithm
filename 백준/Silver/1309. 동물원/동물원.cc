#include <iostream>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    if (N == 1)
    {
        cout << 3 << '\n';
        return 0;
    }

    int First = 3;
    int Second = 2;

    for (int i = 3; i <= N; ++i)
    {
        int NewFirst = (First + Second + Second) % 9901;
        int NewSecond = (First + Second) % 9901;

        First = NewFirst;
        Second = NewSecond;
    }

    cout << (First + Second + Second) % 9901 << '\n';
    
    return 0;
}