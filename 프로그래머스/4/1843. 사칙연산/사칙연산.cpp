#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

inline int MAX(int A, int B) { return A > B ? A : B; }
inline int MIN(int A, int B) { return A < B ? A : B; }

// dp[0] max result
// dp[1] min result
vector<vector<pair<int,int>>> dp;

pair<int, int> DP(vector<string>& arr, int start, int end)
{
    if (dp[start][end].first == -987'654'321)
    {
        if (start == end)
        {
            int num = stoi(arr[start]);
            dp[start][end] = {num, num};
            return dp[start][end];
        }

        int maxNum = -987'654'321;
        int minNum = 987'654'321;

        int result1, result2;

        for (int i = start + 1; i < end; i += 2)
        {
            pair<int, int> leftNum = DP(arr, start, i - 1);
            pair<int, int> rightNum = DP(arr, i + 1, end);

            if (arr[i] == "+")
            {
                result1 = leftNum.first + rightNum.first;
                result2 = leftNum.second + rightNum.second;
            }
            else
            {
                result1 = leftNum.first - rightNum.second;
                result2 = leftNum.second;

                if (rightNum.first > 0 && rightNum.second > 0)
                {
                    result2 -= rightNum.first;
                }
                else if (rightNum.first < 0 && rightNum.second < 0)
                {
                    result2 -= rightNum.second;
                }
                else
                {
                    result2 -= rightNum.first;
                }
            }

            maxNum = MAX(maxNum, result1);
            minNum = MIN(minNum, result2);
        }

        dp[start][end] = { maxNum, minNum };
    }

    return dp[start][end];
}

int solution(vector<string> arr)
{
    dp = vector<vector<pair<int,int>>>(202, vector<pair<int,int>>(202, {-987'654'321, 987'654'321}));

    return DP(arr, 0, arr.size() - 1).first;
}