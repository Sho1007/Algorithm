#include <iostream>
#include <map>
using namespace std;

int N;
long long Input;
map<long long, int> Map;
long long Answer;
int Count = -1;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while (N-->0)
    {
        cin >> Input;
        Map[Input]++;
    }

    for (const pair<long long, int>& Iter : Map)
    {
        if (Iter.second > Count)
        {
            Answer = Iter.first;
            Count = Iter.second;
        }
    }

    cout << Answer  << '\n';

    
    
    return 0;
}