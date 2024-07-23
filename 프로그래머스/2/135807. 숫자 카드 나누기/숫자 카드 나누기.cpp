#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int GCD(int A, int B)
{
    if (B == 0) return A;
    return GCD(B, A % B);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int Current = arrayA[0];
    
    for (int i = 1; i < arrayA.size(); ++i)
    {
        Current = GCD(Current, arrayA[i]);
        if (Current == 1) break;
    }
    for (int i = 0; i < arrayB.size(); ++i)
    {
        if (arrayB[i] % Current == 0)
        {
            Current = 0;
            break;
        }
    }
    
    answer = Current;
    
    Current = arrayB[0];
    for (int i = 1; i < arrayB.size(); ++i)
    {
        Current = GCD(Current, arrayB[i]);
        if (Current == 1) break;
    }
    
    for (int i = 0; i < arrayA.size(); ++i)
    {
        if (arrayA[i] % Current == 0)
        {
            Current = 0;
            break;
        }
    }
    
    answer = answer > Current ? answer : Current;
    
    return answer;
}