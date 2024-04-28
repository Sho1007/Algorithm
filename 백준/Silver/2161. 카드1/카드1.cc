#include <iostream>
#include <queue>
using namespace std;

int N;

queue<int> Queue;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        Queue.push(i);
    }
    
    while (Queue.size() > 1)
    {
        cout << Queue.front() << ' ';
        Queue.pop();
        Queue.push(Queue.front());
        Queue.pop();
    }
    
    cout << Queue.front() << '\n';
    
    return 0;
}