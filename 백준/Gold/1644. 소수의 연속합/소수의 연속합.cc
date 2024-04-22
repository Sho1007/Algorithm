#include <iostream>
#include <vector>
using namespace std;

int N;

bool IsNotPrime[4'000'001] = {};

vector<int> PrimeVector;
vector<int> Sum;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    if (N == 1)
    {
        cout << "0\n";
        return 0;
    }

    for (int i = 2; i <= N; ++i)
    {
        if (IsNotPrime[i] == true) continue;
        PrimeVector.push_back(i);
        
        for (int j = 2; i * j <= N; ++j)
        {
            IsNotPrime[i * j] = true;
        }
    }

    int Answer = 0;
    Sum = vector<int>(PrimeVector.size());

    Sum[0] = PrimeVector[0];

    int Left = 0, Right = 0, Sum = PrimeVector[0];
    while (Left < PrimeVector.size() && Right < PrimeVector.size())
    {
        if (Left > Right)
        {
            Right = Left;
            Sum = PrimeVector[Right];
        }
        
        if (Sum < N)
        {
            if (++Right >= PrimeVector.size()) break;

            Sum += PrimeVector[Right];
        }
        else if (N < Sum)
        {
            Sum -= PrimeVector[Left++];
        }
        else if (Sum == N)
        {
            Answer++;
            Sum -= PrimeVector[Left++];
        }
    }

    cout << Answer << '\n';
    
    return 0;
}