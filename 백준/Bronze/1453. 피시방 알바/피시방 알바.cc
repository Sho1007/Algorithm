#include <iostream>
#include <vector>
using namespace std;

int N, Answer = 0;
bool Seat[101] = {};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    
    int Num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> Num;
        if (Seat[Num] == false)
        {
            Seat[Num] = true;
        }
        else
        {
            Answer++;
        }
    }
    
    cout << Answer << '\n';
    
    return 0;
}