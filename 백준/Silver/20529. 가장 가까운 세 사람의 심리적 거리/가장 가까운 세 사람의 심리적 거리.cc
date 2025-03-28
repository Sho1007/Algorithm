#include <iostream>
#include <string>
#include <vector>
using namespace std;
inline int GetDistance(const string& A, const string& B)
{
    int Distance = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (A[i] != B[i])
        {
            Distance++;
        }
    }
    
    return Distance;
}
inline int MIN(int A, int B) { return A < B ? A : B; }

int T, N;
vector<string> Array;



int TestCast()
{
    int Answer = 987'654'321;
    
    cin >> N;
    Array = vector<string>(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }
    
    if (N > 32)
    {
        return 0;
    }
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                Answer = MIN(Answer, GetDistance(Array[i], Array[j]) + GetDistance(Array[i], Array[k]) + GetDistance(Array[j], Array[k]));
            }
        }
    }
    
    return Answer;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> T;
    
    while (T-->0)
    {
        cout << TestCast() << '\n';
    }
    
    return 0;
}