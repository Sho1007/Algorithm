#include <iostream>
using namespace std;

typedef struct Node
{
	int Data;
	Node* NextNode;
	Node* PrevNode;

	Node(int NewData) : Data(NewData), NextNode(nullptr), PrevNode(nullptr) {}
} Node;

class CircularLinkedList
{
public:
	CircularLinkedList() : Head(nullptr), Tail(nullptr), Count(0) {}
	~CircularLinkedList()
	{
		while (Count-- > 0)
		{
			Node* DeleteTarget = Head;
			Head = Head->NextNode;

			delete DeleteTarget;
		}
	}

	void AppendNode(Node* NewNode)
	{
		if (Head == nullptr)
		{
			Head = NewNode;
			Head->NextNode = Head;
			Head->PrevNode = Head;
			Tail = NewNode;
		}
		else
		{
			NewNode->PrevNode = Tail;
			NewNode->NextNode = Head;
			Tail->NextNode = NewNode;
			Head->PrevNode = NewNode;
			Tail = NewNode;
		}

		Count++;

		//Print();
	}

	void MoveHead(int MoveCount)
	{
		MoveCount--;
		while (MoveCount--> 0)
		{
			Head = Head->NextNode;
		}
	}

	void RemoveHead()
	{
		Node* RemoveNode = Head;
		cout << Head->Data;
		if (Count > 1) cout << ", ";
		Head->PrevNode->NextNode = Head->NextNode;
		Head->NextNode->PrevNode = Head->PrevNode;
		Head = Head->NextNode;
		Count--;

		//Print();
	}

	void Print()
	{
		for (int i = 0; i < Count; ++i)
		{
			cout << Head->Data << ' ';
			Head = Head->NextNode;
		}
		cout << '\n';
	}

	int GetCount() { return Count; }
private:
	Node* Head;
	Node* Tail;
	int Count;
};

int main()
{
	CircularLinkedList* CLL = new CircularLinkedList();

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		CLL->AppendNode(new Node(i));
	}

	cout << '<';
	while (CLL->GetCount() > 0)
	{
		CLL->MoveHead(K);
		CLL->RemoveHead();
	}
	cout << ">\n";

	delete CLL;

	return 0;
}