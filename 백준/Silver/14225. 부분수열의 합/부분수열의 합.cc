#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Array;
bool IsPossible[2'000'000] = {};

void BT(int Current, int Sum)
{
    IsPossible[Sum] = true;

    for (int i = Current + 1; i < N; ++i)
    {
        BT(i, Sum + Array[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    Array = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    BT(-1, 0);

    for (int i = 1; i <= 2'000'000; ++i)
    {
        if (IsPossible[i] == false)
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}