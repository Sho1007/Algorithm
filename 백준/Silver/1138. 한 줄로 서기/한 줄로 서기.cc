#include <iostream>
using namespace std;

int N, Input;
int Order[11] = {};

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> Input;
        for (int j = 1; j <= N; ++j)
        {
            if (Order[j] == 0)
            {
                if (Input == 0)
                {
                    Order[j] = i;
                    break;
                }
                else
                {
                    Input--;                    
                }
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        cout << Order[i] << ' ';
    }
    
    return 0;
}