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
        // 루트 노드까지 반복
        while (pos / 2 != 0)
        {
            int parentPos = pos / 2;
            // 부모가 나보다 크다면 종료 (최대 힙)
            if (arr[pos] < arr[parentPos]) break;

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
                // 왼쪽 자식이 더 큰 경우 (최대 힙)
                if (arr[pos * 2] > arr[pos * 2 + 1])
                {
                    // 내가 자식보다 작다면 교체 후 내려감 (최대 힙)
                    if (arr[pos] < arr[pos * 2])
                    {
                        int temp = arr[pos];
                        arr[pos] = arr[pos * 2];
                        arr[pos * 2] = temp;

                        pos = pos * 2;
                    }
                    else break;
                }
                // 오른쪽 자식이 더 크거나 같은 경우 (최대 힙)
                else
                {
                    // 내가 자식보다 작다면 교체 후 내려감 (최대 힙)
                    if (arr[pos] < arr[pos * 2 + 1])
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
                // 내가 자식보다 작다면 교체 후 내려감 (최대 힙)
                if (arr[pos] < arr[pos * 2])
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