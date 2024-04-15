#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count[5'000'001] = {};
int dp[5'000'001] = {};

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    for (long long i = 1; i <= 5'000'000; ++i)
    {
        for (long long j = 1; j <= 5'000'000; ++j)
        {
            long long Result = i * j;
            if (Result > 5'000'000) break;
            
            count[Result]++;
        }
    }
    
    dp[e] = e;
    
    for (int i = e-1; i > 0; --i)
    {
        if (count[dp[i+1]] <= count[i]) dp[i] = i;
        else dp[i] = dp[i+1];
    }
    
    for (int i = 0; i < starts.size(); ++i)
    {
        answer.push_back(dp[starts[i]]);
    }
    
    return answer;
}