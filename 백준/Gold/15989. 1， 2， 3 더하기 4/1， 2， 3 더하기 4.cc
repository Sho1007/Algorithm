#include <iostream>
using namespace std;

int N, Input;
int DP[10'001][4] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    DP[1][1] = 1;
    
    DP[2][1] = 1;
    DP[2][2] = 1;
    
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;
    
    for (int i = 4; i < 10'001; ++i)
    {
        DP[i][1] = 1;
        DP[i][2] = DP[i-2][1] + DP[i-2][2];
        DP[i][3] = DP[i-3][1] + DP[i-3][2] + DP[i-3][3];
    }
    
    while (N-->0)
    {
        cin >> Input;
        cout << DP[Input][1] + DP[Input][2] + DP[Input][3] << '\n';
    }
    
    return 0;
}