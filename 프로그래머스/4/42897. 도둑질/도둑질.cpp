#include <string>
#include <vector>
#include <iostream>
inline int MAX(int A, int B) { return A > B ? A : B; }

using namespace std;

vector<int> dp[4];
// 0 : 첫 번째 훔침
// 1 : 첫 번째 훔침 (사실 안훔침)
// 2 : 첫 번째 안훔침
// 3

int answer = 0;

int solution(vector<int> money)
{
    for (int i = 0; i < 4; ++i)
    {
        dp[i] = vector<int>(money.size(), 0);
    }
    
    dp[0][0] = money[0];
    
    for (int i = 1; i < money.size()-1; ++i)
    {
        dp[0][i] = dp[1][i-1] + money[i];
        dp[1][i] = MAX(dp[0][i-1], dp[1][i-1]);
        dp[2][i] = dp[3][i-1] + money[i];
        dp[3][i] = MAX(dp[2][i-1], dp[3][i-1]);
    }
    
    dp[2][money.size()-1] = dp[3][money.size()-2] + money.back();
    
    answer = MAX(dp[0][money.size()-2], MAX(dp[1][money.size()-2], MAX(dp[2][money.size()-2], MAX(dp[3][money.size()-2], dp[2][money.size()-1]))));
    
    return answer;
}