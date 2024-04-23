#include <iostream>
using namespace std;

int N;

int dp[100'001] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i <= N; i += 2)
    {
        if (i != 0)
        {
            if (dp[i] == 0 || dp[i] > dp[i-2] + 1)
            {
                dp[i] = dp[i-2] + 1;
            }
        }
        for (int j = i + 5; j <= N; j += 5)
        {
            dp[j] = dp[j-5] + 1;
        }
    }

    if (dp[N] == 0) cout << "-1\n";
    else cout << dp[N] << '\n';
    
    return 0;
}