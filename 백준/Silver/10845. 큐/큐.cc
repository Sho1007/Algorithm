#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue
{
public:
	Queue(int NewCapacity ) : Capacity(NewCapacity + 1), Front(0), Rear(0)
	{
		Array = vector<int>(Capacity, 0);
	}

	bool IsEmpty()
	{
		return Front == Rear;
	}

	bool IsFull()
	{
		return (Rear + 1) % Capacity == Front;
	}

	void Print()
	{
		if (IsEmpty()) return;

		cout << Count() << " : ";
		int Current = Front;
		while ((Current + 1) % Capacity != Front)
		{
			cout << Array[Current] << ' ';
			Current = (Current + 1) % Capacity;
		}
		cout << '\n';
	}

	void Push(int NewData)
	{
		if (IsFull()) return;

		Array[Rear] = NewData;
		Rear = (Rear + 1) % Capacity;

		//Print();
	}

	int Pop()
	{
		if (IsEmpty()) return -1;

		int Data = Array[Front];
		Array[Front] = 0;
		Front = (Front + 1) % Capacity;

		//Print();

		return Data;
	}

	int GetFront()
	{
		if (IsEmpty()) return -1;

		return Array[Front];
	}

	int GetBack()
	{
		if (IsEmpty()) return -1;

		return Array[Rear-1];
	}

	int Count()
	{
		if (IsEmpty()) return 0;
		if (Rear > Front)
		{
			return Rear - Front;
		}
		else
		{
			return Capacity - Front + Rear;
		}
	}

private:
	int Capacity;
	int Front;
	int Rear;
	vector<int> Array;
};

int N, Input;
string Order;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	Queue* Q = new Queue(N);

	while (N-->0)
	{
		cin >> Order;

		if (Order == "push")
		{
			cin >> Input;
			Q->Push(Input);
		}
		else if (Order == "pop")
		{
			cout << Q->Pop() << '\n';
		}
		else if (Order == "size")
		{
			cout << Q->Count() << '\n';
		}
		else if (Order == "empty")
		{
			cout << Q->IsEmpty() << '\n';
		}
		else if (Order == "front")
		{
			cout << Q->GetFront() << '\n';
		}
		else if (Order == "back")
		{
			cout << Q->GetBack() << '\n';
		}
	}

	delete Q;

	return 0;
}