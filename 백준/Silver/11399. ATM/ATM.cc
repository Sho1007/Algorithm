#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> Vector;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    Vector = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Vector[i];
    }

    sort(Vector.begin(), Vector.end());

    int Answer = Vector[0];
    for (int i = 1; i < Vector.size(); ++i)
    {
        Vector[i] += Vector[i-1];
        Answer += Vector[i];
    }

    cout << Answer << '\n';
    
    return 0;
}