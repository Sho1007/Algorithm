#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, Input;

vector<int> Vector;
stack<int> Stack;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int Current = 1;

    Vector = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        while (Stack.empty() == false && Stack.top() == Current)
        {
            Stack.pop();
            Current++;
        }

        if (Current == Input)
        {
            Current++;
        }
        else
        {
            Stack.push(Input);
        }
    }

    while (Stack.empty() == false)
    {
        if (Stack.top() == Current)
        {
            Current++;
            Stack.pop();
        }
        else
        {
            cout << "Sad\n";
            return 0;
        }
    }

    cout << "Nice\n";
    
    return 0;
}