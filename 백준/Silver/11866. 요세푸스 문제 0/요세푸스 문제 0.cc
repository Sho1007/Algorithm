#include <iostream>
#include <vector>
using namespace std;

int N, K;

vector<int> Vector;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    Vector = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        Vector[i] = i + 1;
    }

    int CurrentPos = 0;

    cout << '<';
    while (true)
    {
        CurrentPos = (CurrentPos + K - 1) % Vector.size();
        cout << Vector[CurrentPos];
        Vector.erase(Vector.begin() + CurrentPos);

        if (Vector.size() > 0)
        {
            cout << ", ";
        }
        else
        {
            cout << ">\n";
            break;
        }
    }
    
    return 0;
}