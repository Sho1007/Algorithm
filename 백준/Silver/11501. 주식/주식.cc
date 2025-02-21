#include <iostream>
#include <vector>
using namespace std;
int T, N;
vector<int> PriceVector;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T-- > 0)
    {
        cin >> N;
        PriceVector = vector<int>(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> PriceVector[i];
        }

        long long Answer = 0;
        int MaxNum = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            if (PriceVector[i] > MaxNum)
            {
                MaxNum = PriceVector[i];
            }
            else
            {
                Answer += (MaxNum - PriceVector[i]);
            }
        }

        cout << Answer << '\n';
    }

    return 0;
}