#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

inline double Distance(int Y, int X)
{
    long long YPow = (long long)Y * (long long)Y;
    long long XPow = (long long)X * (long long)X;
    
    //cout << YPow << " + " << XPow << " : " << sqrt((YPow + XPow)) << '\n';
    
    return (double)sqrt(YPow + XPow);
}

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i = 0; i * k <= d; ++i)
    {
        int Current = i * k;
        
        long long Remain = ((long long)d * (long long)d) - ((long long)Current * (long long )Current);
        answer += ((int)sqrt(Remain) / k) + 1;
    }
    
    return answer;
}