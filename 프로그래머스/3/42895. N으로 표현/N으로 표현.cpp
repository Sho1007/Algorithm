#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> dp[9];

int solution(int N, int number) {
    int num = 0;
    
    for (int i = 1; i <= 8; ++i)
    {
        num *= 10;
        num += N;
        dp[i].insert(num);
        
        for (int j = 1; i - j > 0; ++j)
        {
            for (int A : dp[i-j])
            {
                for (int B : dp[j])
                {
                    dp[i].insert(A + B);
                    if (A - B > 0) dp[i].insert(A - B);
                    dp[i].insert(A * B);
                    if (A / B > 0) dp[i].insert(A / B);
                }
            }
        }
    }
    for (int i = 1; i <= 8; ++i)
    {
        if (dp[i].find(number) != dp[i].end()) return i;
    }
    
    return -1;
}