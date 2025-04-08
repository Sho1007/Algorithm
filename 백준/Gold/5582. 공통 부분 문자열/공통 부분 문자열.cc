#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int MAX(int A, int B) { return A > B ? A : B; }

string A, B;
int dp[4001][4001] = {};
int Answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> A >> B;
    
    for (int i = 1; i <= A.length(); ++i)
    {
        for (int j = 1; j <= B.length(); ++j)
        {
            if (A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                
                Answer = MAX(Answer, dp[i][j]);
            }
        }
    }
    
    cout << Answer << '\n';
    
    return 0;
}