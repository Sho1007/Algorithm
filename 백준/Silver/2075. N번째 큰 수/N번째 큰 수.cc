#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Input;
vector<int> Array;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    Array = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    sort(Array.begin(), Array.end());

    for (int j = 0; j < N - 1; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> Input;
            if (Input > Array[0])
            {
                Array.insert(upper_bound(Array.begin(), Array.end(), Input), Input);
                Array.erase(Array.begin());
            }
        }
    }

    cout << Array[0] << '\n';

    return 0;
}