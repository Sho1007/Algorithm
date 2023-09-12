#include <iostream>
using namespace std;

class Stack
{
public:
    Stack(int NewCapacity = 1'000'000) : Capacity(NewCapacity), Top(0)
    {
        Array = new int[Capacity + 1];
    }
    ~Stack()
    {
        delete[] Array;
    }
    void Push(int Data)
    {
        if (Top > Capacity) return; // Out Of Bound

        Array[Top++] = Data;
    }
    int IsEmpty()
    {
        return Top == 0;
    }
    int Pop()
    {
        if (IsEmpty()) return -1;

        return Array[--Top];
    }
    int GetCount()
    {
        return Top;
    }
    int GetTopData()
    {
        if (IsEmpty()) return -1;

        return Array[Top - 1];
    }
private:
    int* Array;
    int Capacity;
    int Top;
};

int N, Command, X;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Stack* stack = new Stack();

    cin >> N;

    while (N-- > 0)
    {
        cin >> Command;
        switch (Command)
        {
        case 1:
            cin >> X;
            stack->Push(X);
            break;
        case 2:
            cout << stack->Pop() << '\n';
            break;
        case 3:
            cout << stack->GetCount() << '\n';
            break;
        case 4:
            cout << stack->IsEmpty() << '\n';
            break;
        case 5:
            cout << stack->GetTopData() << '\n';
            break;
        }
    }

    delete stack;

    return 0;
}