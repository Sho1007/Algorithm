#include <iostream>
using namespace std;

typedef struct Node
{
	int Data;
	Node* NextNode;

	Node(int NewData) : Data(NewData), NextNode(nullptr) {}
} Node;

class SingleLinkedList
{
public:
	~SingleLinkedList()
	{
		while (Head != nullptr)
		{
			Node* DeleteNode = Head;
			Head = Head->NextNode;
			delete DeleteNode;
		}
	}

	void Print()
	{
		cout << "Data : ";
		Node* Current = Head;
		while (Current != nullptr)
		{
			cout << Current->Data << ' ';
			Current = Current->NextNode;
		}
		cout << '\n';
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

	int Find(int TargetData)
	{
		Node* Current = Head;
		int Result = 0;
		while (Current != nullptr)
		{
			if (Current->Data == TargetData) Result++;

			Current = Current->NextNode;
		}

		return Result;
	}


private:
	Node* Head;
	Node* Tail;
	int Count;
};

int N, Input;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> N;

	SingleLinkedList* SLL = new SingleLinkedList();

	for (int i = 1; i <= N; ++i)
	{
		cin >> Input;
		SLL->AppendNode(new Node(Input));
	}

	cin >> Input;

	cout << SLL->Find(Input) << '\n';

	delete SLL;

	return 0;
}