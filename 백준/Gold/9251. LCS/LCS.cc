#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

inline int Max(int a, int b) { return a > b ? a : b; }

string A, B;
int** arr;

void Print()
{
    cout << "--------------------- Print ---------------------" << endl;

    for (int i = 0; i <= A.length(); ++i)
    {
        for (int j = 0; j <= B.length(); ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

int main()
{
    cin >> A >> B;

    // Init
    arr = new int* [A.length() + 1];
    for (int i = 0; i <= A.length(); ++i)
    {
        arr[i] = new int[B.length() + 1];
        fill(arr[i], arr[i] + B.length() + 1, 0);
    }

    for (int i = 1; i <= A.length(); ++i)
    {
        for (int j = 1; j <= B.length(); ++j)
        {
            if (A[i - 1] == B[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = Max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    cout << arr[A.length()][B.length()] << endl;

    // Delete
    for (int i = 0; i <= A.length(); ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}