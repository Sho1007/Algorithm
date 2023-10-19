#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> BoxStack;

int solution(vector<int> Order) {
    int OrderPos = 0;
    
    for (int i = 1; i <= Order.size();)
    {
        if (BoxStack.size() > 0 && BoxStack.top() == Order[OrderPos])
        {
            OrderPos++;
            BoxStack.pop();
        }
        else if (i == Order[OrderPos])
        {
            OrderPos++;
            i++;
        }
        else
        {
            BoxStack.push(i++);
        }
    }
    
    while (!BoxStack.empty())
    {
        if (BoxStack.top() == Order[OrderPos])
        {
            OrderPos++;
            BoxStack.pop();
        }
        else break;
    }
    
    
    
    cout << '\n';
    
    return OrderPos;
}