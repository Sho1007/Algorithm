#include <iostream>
#include <string>
using namespace std;

int K;

char Symbol;
string Path;
string Source;

struct Node
{
	int Symbol;
	Node* Left;
	Node* Right;

	Node(int NewSymbol) : Symbol(NewSymbol), Left(nullptr), Right(nullptr) {}

	void DeleteNode()
	{
		if (Left) Left->DeleteNode();
		if (Right) Right->DeleteNode();
		delete this;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> K;

	Node* HuffmanTree = new Node(0);

	for (int i = 0; i < K; ++i)
	{
		cin >> Symbol >> Path;

		Node* Current = HuffmanTree;
		
		for (int j = 0; j < Path.size(); ++j)
		{
			if (Path[j] == '0')
			{
				if (Current->Left == nullptr)
				{
					Current->Left = new Node(0);
				}
				Current = Current->Left;
			}
			else
			{
				// Path[j] == 1

				if (Current->Right == nullptr)
				{
					Current->Right = new Node(0);
				}
				Current = Current->Right;
			}
		}

		Current->Symbol = Symbol;
	}

	cin >> Source;

	Node* Current = HuffmanTree;

	for (int i = 0; i < Source.size(); ++i)
	{
		if (Source[i] == '0')
		{
			Current = Current->Left;
		}
		else
		{
			Current = Current->Right;
		}

		if (Current->Symbol != 0)
		{
			cout << (char)(Current->Symbol);
			Current = HuffmanTree;
		}
	}

	return 0;
}