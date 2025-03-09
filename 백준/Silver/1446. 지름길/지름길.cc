#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987'654'321
using namespace std;

int N, D, Start, End, TempCost;
vector<int> Cost;
int Current = 0;
vector<vector<int>> ShortCut;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> D;

    Cost = vector<int>(D + 1, INF);

    Cost[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        cin >> Start >> End >> TempCost;
        ShortCut.push_back({ Start, End, TempCost });
    }

    sort(ShortCut.begin(), ShortCut.end(), [](vector<int>& A, vector<int>& B)->bool
        {
            if (A[0] == B[0])
            {
                if (A[1] == B[1])
                {
                    return A[2] < B[2];
                }
                return A[1] < B[1];
            }
            return A[0] < B[0];
        });

    for (int i = 0; i <= D; ++i)
    {
        if (i > 0 && (Cost[i] == INF || Cost[i] > Cost[i - 1] + 1))
        {
            Cost[i] = Cost[i - 1] + 1;
        }

        while (Current < ShortCut.size() && i == ShortCut[Current][0])
        {
            if (ShortCut[Current][1] <= D)
            {
                int NextCost = ShortCut[Current][2] + Cost[i];
                if (Cost[ShortCut[Current][1]] > NextCost)
                {
                    Cost[ShortCut[Current][1]] = NextCost;
                }
            }
            Current++;
        }
    }

    cout << Cost[D] << '\n';

    return 0;
}