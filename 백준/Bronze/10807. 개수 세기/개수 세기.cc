#include <iostream>
#include <map>
using namespace std;

int N, Input, Target;

map<int,int> Map;

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        Map[Input]++;
    }
    
    cin >> Target;
    
    cout << Map[Target] << '\n';
    
    return 0;
}