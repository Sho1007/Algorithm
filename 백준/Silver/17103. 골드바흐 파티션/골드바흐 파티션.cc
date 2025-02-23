#include <iostream>
#include <vector>
using namespace std;

vector<bool> IsPrime;
vector<int> Primes;

int T, N, Count;

int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    IsPrime = vector<bool>(1'000'001, true);

    for (int i = 2; i <= 1'000'000; ++i)
    {
        if (IsPrime[i] == false) continue;
        Primes.push_back(i);

        for (int j = 2; i * j <= 1'000'000; ++j)
        {
            IsPrime[i * j] = false;
        }
    }

    cin >> T;

    while (T-- > 0)
    {
        cin >> N;
        Count = 0;
        int Half = N / 2;
        for (int i = 0; i < Primes.size(); ++i)
        {
            if (Primes[i] > Half) break;

            if (IsPrime[N - Primes[i]])
            {
                Count++;
            }
        }
        cout << Count << '\n';
    }

    return 0;
}