#include <iostream>

#define endl '\n'

using namespace std;

class MyHeap
{
public:
    MyHeap()
    {
        arr[0] = 0;
    }

    void Print()
    {
        for (int i = 0; i <= arr[0]; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Push(int data)
    {
        arr[0]++;
        int pos = arr[0];
        arr[pos] = data;
        while (pos / 2 != 0)
        {
            int parentPos = pos / 2;
            if (arr[pos] > arr[parentPos]) break;

            int temp = arr[pos];
            arr[pos] = arr[parentPos];
            arr[parentPos] = temp;

            pos = parentPos;
        }

        //Print();
    }

    int Delete()
    {
        if (arr[0] == 0) return 0;
        int num = arr[1];
        int pos = 1;
        arr[pos] = arr[arr[0]];
        arr[arr[0]] = 0;
        arr[0]--;
        
        // 자식이 있는 경우 반복
        while (pos * 2 <= arr[0])
        {
            // 왼쪽 오른쪽 자식 다 있는 경우
            if (pos * 2 + 1 <= arr[0])
            {
                // 왼쪽 자식이 더 작은 경우
                if (arr[pos * 2] < arr[pos * 2 + 1])
                {
                    if (arr[pos] > arr[pos * 2])
                    {
                        int temp = arr[pos];
                        arr[pos] = arr[pos * 2];
                        arr[pos * 2] = temp;

                        pos = pos * 2;
                    }
                    else break;
                }
                // 오른쪽 자식이 더 작거나 같은 경우
                else
                {
                    if (arr[pos] > arr[pos * 2 + 1])
                    {
                        int temp = arr[pos];
                        arr[pos] = arr[pos * 2 + 1];
                        arr[pos * 2 + 1] = temp;

                        pos = pos * 2 + 1;
                    }
                    else break;
                }
            }
            else
            {
                if (arr[pos] > arr[pos * 2])
                {
                    int temp = arr[pos];
                    arr[pos] = arr[pos * 2];
                    arr[pos * 2] = temp;

                    pos = pos * 2;
                }
                else break;
            }

            
        }

        //Print();

        return num;
    }

private:
    int arr[100'001] = {};
};


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    MyHeap* heap = new MyHeap();

    int N, num;
    cin >> N;
    while(N-- > 0)
    {
        cin >> num;
        if (num == 0)
            cout << heap->Delete() << endl;
        else
            heap->Push(num);
    }
    delete heap;

    return 0;
}