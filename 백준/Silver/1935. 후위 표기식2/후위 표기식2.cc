#include <iostream>
#include <string>
using namespace std;

int N;
string String;
double DataArray[26] = {};

typedef struct Node
{
	char Data;

	Node* Parent;
	Node* LeftChild;
	Node* RightChild;

	double Calc()
	{
		double Left;
		double Right;
		if ('A' <= Data && Data <= 'Z')
		{
			return DataArray[Data - 'A'];
		}
		else
		{
			Left = LeftChild->Calc();
			Right = RightChild->Calc();
		}

		double Result = 0;
		switch (Data)
		{
		case '+':
			Result = Left + Right;
			break;
		case '-':
			Result = Left - Right;
			break;
		case '*':
			Result = Left * Right;
			break;
		case '/':
			Result = Left / Right;
			break;
		}

		return Result;
	}

	void DeleteAll()
	{
		if (LeftChild != nullptr)
		{
			LeftChild->DeleteAll();
		}
		if (RightChild != nullptr)
		{
			RightChild->DeleteAll();
		}

		delete this;
	}

	Node(char NewData) : Data(NewData), Parent(nullptr), LeftChild(nullptr), RightChild(nullptr) {}
} Node;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout.setf(ios::fixed);
	cout.precision(2);

	cin >> N;
	cin >> String;
	for (int i = 0; i < N; ++i)
	{
		cin >> DataArray[i];
	}

	Node* Root = nullptr;

	Node** Current = &Root;

	for (int i = String.size()-1; i >= 0; --i)
	{
		Node* NewNode = new Node(String[i]);
		if (*Current == nullptr)
		{
			*Current = NewNode;
		}
		else
		{
			while (true)
			{
				if ((*Current)->RightChild == nullptr)
				{
					(*Current)->RightChild = NewNode;
					NewNode->Parent = *Current;

					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						Current = &(*Current)->RightChild;
					}
					break;
				}
				else if ((*Current)->LeftChild == nullptr)
				{
					(*Current)->LeftChild = NewNode;
					NewNode->Parent = *Current;

					if (!('A' <= String[i] && String[i] <= 'Z'))
					{
						Current = &(*Current)->LeftChild;
					}
					break;
				}
				else
				{
					Current = &(*Current)->Parent;
				}
			}
		}
	}

	if (Root != nullptr)
	{
		cout << Root->Calc() << '\n';

		delete Root;
	}

	return 0;
}