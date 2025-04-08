#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A, B;
vector<vector<int>> SubstringLength;
int Answer = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> A >> B;
    
    SubstringLength = vector<vector<int>>(A.length(), vector<int>(B.length()));
    
    for (int i = 0; i < A.length(); ++i)
    {
        for (int j = 0; j < B.length(); ++j)
        {
            if (A[i] == B[j])
            {
                if (i > 0 && j > 0 && SubstringLength[i-1][j-1] > 0)
                {
                    SubstringLength[i][j] = SubstringLength[i-1][j-1] + 1;
                }
                else
                {
                    SubstringLength[i][j] = 1;
                }
                
                if (SubstringLength[i][j] > Answer)
                {
                    Answer = SubstringLength[i][j];
                }
            }
            else
            {
                SubstringLength[i][j] = 0;
            }
        }
    }
    
    cout << Answer << '\n';
    
    return 0;
}