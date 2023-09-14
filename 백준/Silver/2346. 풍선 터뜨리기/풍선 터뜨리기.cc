#include <iostream>
#include <vector>
using namespace std;
int N, Input;
vector<int> Answer;

typedef struct Node
{
    int Index;
    int Data;
    Node* PrevNode;
    Node* NextNode;

    Node(int NewIndex, int NewData) : Index(NewIndex), Data(NewData), PrevNode(nullptr), NextNode(nullptr) {}
} Node;

class CircularLinkedList
{
public:
    CircularLinkedList() : Head(nullptr), Tail(nullptr), Count(0) {}
    ~CircularLinkedList()
    {
        Node* DeleteTarget;
        while (Count-- > 0)
        {
            DeleteTarget = Head;
            Head = Head->NextNode;

            delete DeleteTarget;
        }
    }
    Node* CreateNode(int Index, int Data)
    {
        return new Node(Index, Data);
    }
    void AddNode(Node* NewNode)
    {
        if (NewNode == nullptr) return;

        if (Count == 0)
        {
            Head = NewNode;
            Tail = NewNode;
            Head->NextNode = Head;
            Head->PrevNode = Head;
        }
        else
        {
            NewNode->NextNode = Head;
            NewNode->PrevNode = Tail;
            Tail->NextNode = NewNode;
            Head->PrevNode = NewNode;

            Tail = NewNode;
        }
        Count++;
    }

    void RemoveHead()
    {
        if (Count == 0) return;
        else if (Count == 1)
        {
            delete Head;
            Head = nullptr;
            Tail = nullptr;
        }
        else
        {
            Node* DeleteTarget = Head;
            Head->NextNode->PrevNode = Tail;
            Tail->NextNode = Head->NextNode;
            Head = Head->NextNode;
            delete DeleteTarget;
        }
        Count--;
    }

    void MoveLeft(int MoveCount)
    {
        if (Count < 2) return;
        while (MoveCount-- > 0)
        {
            Head = Head->PrevNode;
        }
        Tail = Head->PrevNode;
    }

    void MoveRight(int MoveCount)
    {
        if (Count < 2) return;
        while (MoveCount-- > 0)
        {
            Head = Head->NextNode;
        }
        Tail = Head->PrevNode;
    }

    void Explode()
    {
        Answer.push_back(Head->Index);
        int MoveCount = Head->Data;
        RemoveHead();
        if (Count > 0)
        {
            if (MoveCount > 0)
            {
                MoveRight(--MoveCount);
            }
            else
            {
                MoveLeft(-MoveCount);
            }
            Explode();
        }
    }

private:
    Node* Head;
    Node* Tail;
    int Count;
};

int main()
{
    cin >> N;

    CircularLinkedList* CLL = new CircularLinkedList();

    for (int i = 1; i <= N; ++i)
    {
        cin >> Input;
        CLL->AddNode(CLL->CreateNode(i, Input));
    }

    CLL->Explode();

    for (int Iter : Answer)
    {
        cout << Iter << ' ';
    }
    cout << '\n';

    delete CLL;
}