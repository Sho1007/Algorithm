#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> dp;

int DP(vector<vector<int>>& triangle, int row, int col)
{
    if (row < 0 || row >= dp.size() || col < 0 || col >= dp[row].size()) return 0;
    
    if (dp[row][col] == -1)
    {
        int left = DP(triangle, row-1, col-1);
        int right = DP(triangle, row-1, col);
        
        dp[row][col] = triangle[row][col] + (left > right ? left : right);
    }
    
    return dp[row][col];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp = vector<vector<int>>(triangle.size());
    for (int i = 0; i < triangle.size(); ++i)
    {
        dp[i] = vector<int>(triangle[i].size(), -1);
    }
    
    int lastRow = triangle.size() - 1;
    for (int i = 0; i < triangle[lastRow].size(); ++i)
    {
        int current = DP(triangle, lastRow, i);
        if (current > answer) answer = current;
    }
    
    return answer;
}