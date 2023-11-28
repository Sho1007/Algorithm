#include <iostream>
using namespace std;

int N, X, Input;

typedef struct Node
{
    int Data;
    Node* NextNode;
    
    Node(int NewData) : Data(NewData) {}
} Node;

class SingleLinkedList
{
public:
    SingleLinkedList() : Head(nullptr), Tail(nullptr), Count(0) {}
    ~SingleLinkedList()
    {
        while (Head != nullptr)
        {
            Node* DeleteNode = Head;
            Head = Head->NextNode;
            delete  DeleteNode;
        }
    }
    
    void AppendNode(Node* NewNode)
    {
        if (Head == nullptr)
        {
            Head = NewNode;
            Tail = NewNode;
        }
        else
        {
            Tail->NextNode = NewNode;
            Tail = NewNode;
        }
        
        Count++;
    }
    
    void PrintNode(int TargetData)
    {
        Node* Current = Head;
        while (Current != nullptr)
        {
            if (Current->Data < TargetData)
            {
                cout << Current->Data << ' ';
            }
            
            Current = Current->NextNode;
        }
        cout << '\n';
    }
    
private:
    Node* Head;
    Node* Tail;
    int Count;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> X;
    
    SingleLinkedList* SLL = new SingleLinkedList();
    
    for (int i = 0; i < N; ++i)
    {
        cin>> Input;
        SLL->AppendNode(new Node(Input));
    }
    
    SLL->PrintNode(X);
    
    delete SLL;
    
    return 0;
}