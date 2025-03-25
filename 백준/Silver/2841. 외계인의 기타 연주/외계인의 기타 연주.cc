#include <iostream>
#include <stack>
using namespace std;

int N, P, Line, Pret, Answer = 0;
stack<int> Stack[6];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> P;

    for (int i = 0; i < N; ++i)
    {
        cin >> Line >> Pret;
        Line--;

        while (!Stack[Line].empty() && Stack[Line].top() > Pret)
        {
            Answer++;
            Stack[Line].pop();
        }

        // 스택이 비어있거나 작은 프렛이 잡혀있다면
        if (Stack[Line].size() == 0 || Stack[Line].top() < Pret)
        {
            Stack[Line].push(Pret);
            Answer++;
        }
        else if (Stack[Line].top() == Pret)
        {
            continue;
        }
    }

    cout << Answer << '\n';

    return 0;
}