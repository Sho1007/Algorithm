#include <string>
#include <vector>

using namespace std;

vector<int> DP;

int Start, End, Add;

int Calc(int Num, int Count)
{
    if (Num < 0 || Num >= DP.size() || Num < Start) return -1;
    
    if (DP[Num] == -1 || DP[Num] > Count)
    {
        DP[Num] = Count;
        if (Num % 2 == 0) Calc(Num / 2, Count + 1);
        if (Num % 3 == 0) Calc(Num / 3, Count + 1);
        Calc(Num - Add, Count + 1);
    }
    
    return DP[Num];
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    DP = vector<int>(1'000'001, -1);
    
    Start = x;
    End = y;
    Add = n;
    
    Calc(End, 0);
    
    return DP[Start];
}