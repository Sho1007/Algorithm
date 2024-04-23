#include <iostream>
#define INF 987'654'321
using namespace std;

inline int MIN(int A, int B) { return A < B ? A : B; }

int N;

int dp[100'001] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[0] = 0;
    dp[1] = INF;
    dp[2] = 1;
    dp[3] = INF;
    dp[4] = 2;

    for (int i = 5; i <= N; ++i)
    {
        dp[i] = MIN(dp[i-2], dp[i-5]) + 1;
        if (dp[i] == INF + 1) dp[i] = INF;
    }

    if (dp[N] == INF) cout << "-1\n";
    else cout << dp[N] << '\n';
    
    return 0;
}