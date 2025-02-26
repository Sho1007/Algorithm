#include <iostream>
#include <vector>
#define INFCOUNT 987'654'321
using namespace std;

vector<int> Array, Count;

int N;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    Array = vector<int>(N + 1);
    Count = vector<int>(N + 1, INFCOUNT);

    Count[1] = 0;
    cin >> Array[1];
    for (int i = 2; i <= Array[1] + 1; ++i)
    {
        if (i >= Array.size()) break;
        Count[i] = 1;
    }

    for (int i = 2; i <= N; ++i)
    {
        cin >> Array[i];

        if (Count[i] == 0) continue;

        for (int j = i + 1; j <= i + Array[i]; ++j)
        {
            if (j >= Count.size()) break;
            if (Count[j] > Count[i] + 1)
            {
                Count[j] = Count[i] + 1;
            }
        }
    }

    cout << (Count[N] == INFCOUNT ? -1 : Count[N]) << '\n';

    return 0;
}