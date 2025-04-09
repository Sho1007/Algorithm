#include <iostream>
using namespace std;

int N;
unsigned long long Answer = 0;
int Heights[80'000] = {};
int DP[80'000] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Heights[i];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        int BlockPos = i + 1;

        while (BlockPos < N && Heights[i] > Heights[BlockPos])
        {
            BlockPos = DP[BlockPos];
        }

        DP[i] = BlockPos;

        Answer += (BlockPos - i - 1);
    }

    cout << Answer << '\n';

    return 0;
}