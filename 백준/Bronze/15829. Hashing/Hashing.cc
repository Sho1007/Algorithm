#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef string KeyType;
typedef string ValueType;

typedef struct Node
{
	KeyType Key;
	ValueType Value;

	Node* NextNode;

	Node(KeyType NewKey, ValueType NewValue) : Key(NewKey), Value(NewValue), NextNode(nullptr) {}
} Node;

class HashTable
{
public:
	HashTable(int NewTableSize) : TableSize(NewTableSize), Table(vector<Node*>(TableSize, nullptr)) {}
	~HashTable()
	{
		for (int i = 0; i < Table.size(); ++i)
		{
			Node* Current = Table[i];
			while (Current != nullptr)
			{
				Node* DeleteTarget = Current;
				Current = Current->NextNode;
				delete DeleteTarget;
			}
		}
	}

	long long Hash(KeyType Key)
	{
		long long HashValue = 0;

		for (int i = 0; i < Key.size(); ++i)
		{
			long long Pow = 1;

			for (int j = 0; j < i; ++j)
			{
				Pow *= 31;
				Pow %= 1234567891;
			}

			//cout << (Key[i] - 'a' + 1) << " * " << Pow << " : " << (Key[i] - 'a' + 1) * Pow << "\n";

			HashValue += Pow * (Key[i] - 'a' + 1);
			HashValue %= 1234567891;

			//cout << "HashValue : " << HashValue << '\n';
		}

		return HashValue;
	}

	void Set(KeyType Key, ValueType Value)
	{
		int Address = Hash(Key);

		Node* NewNode = new Node(Key, Value);
		if (Table[Address] == nullptr)
		{
			Table[Address] = NewNode;
		}
		else
		{
			// Collision
			NewNode->NextNode = Table[Address];

			Table[Address] = NewNode;
		}
	}

	Node* Get(KeyType Key)
	{
		int Address = Hash(Key);

		Node* Current = Table[Address];

		while (Current != nullptr)
		{
			if (Current->Key == Key) return Current;
			Current = Current->NextNode;
		}

		return nullptr;
	}
private:
	int TableSize;
	vector<Node*> Table;
};

int N;
string Target;

int main()
{
	HashTable* HT = new HashTable(193);

	cin >> N >> Target;

	cout << HT->Hash(Target) << '\n';

	delete HT;

	return 0;
}