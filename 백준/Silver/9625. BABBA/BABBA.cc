#include <iostream>
using namespace std;

int K;
unsigned long long dp[46][2] = {};

int main()
{
    cin >> K;
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= K; ++i)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][1];

        dp[i][1] += dp[i-1][0];
    }

    cout << dp[K][0] << ' ' << dp[K][1] << '\n';
    
    return 0;
}