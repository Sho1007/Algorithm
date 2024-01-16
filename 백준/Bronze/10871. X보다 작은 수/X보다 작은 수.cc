#include <iostream>
using namespace std;

int N;
int X;
int Input;

struct Node
{
    int Data;
    Node* NextNode;
    
    Node(int NewData) : Data(NewData), NextNode(nullptr) {}
};

class SingleLinkedList
{
public :
    SingleLinkedList() : Head(nullptr), Tail(nullptr) {}
    ~SingleLinkedList()
    {
        while (Head != nullptr)
        {
            Node* DeleteNode = Head;
            Head = Head->NextNode;
            
            delete DeleteNode;
        }
    }
    
    void FindAndPrint(int Target)
    {
        Node* CurrentNode = Head;
        while (CurrentNode != nullptr)
        {
            if (CurrentNode->Data < Target)
            {
                cout << CurrentNode->Data << ' ';
            }
            CurrentNode = CurrentNode->NextNode;
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
    }
    
private :
    Node* Head;
    Node* Tail;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> X;
    
    SingleLinkedList* SLL = new SingleLinkedList();
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        SLL->AppendNode(new Node(Input));
    }
    
    SLL->FindAndPrint(X);
    
    delete SLL;
    
    return 0;
}