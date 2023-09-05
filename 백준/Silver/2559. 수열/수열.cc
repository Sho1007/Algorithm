#include <iostream>
using namespace std;

int N, K, Input, Sum = 0, MaxNum;

int Temp[100'001] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Temp[i];
        Sum += Temp[i];
        if (i < K)
        {
            if (i == K -1)
            {
                MaxNum = Sum;
            }
        }
        else
        {
            Sum -= Temp[i-K];
            MaxNum = MaxNum > Sum ? MaxNum : Sum;
        }
    }
    
    cout << MaxNum << '\n';
    
    return 0;
}