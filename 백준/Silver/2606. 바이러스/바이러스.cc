#include <iostream>
using namespace std;

int N, M, A, B;

int Parent[101] = {};

int GetParent(int Num)
{
    if (Parent[Num] == Num) return Num;

    return Parent[Num] = GetParent(Parent[Num]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; ++i)
    {
        Parent[i] = i;
    }

    while (M-->0)
    {
        cin >> A >> B;

        int  ParentA = GetParent(A);
        int ParentB = GetParent(B);

        if (ParentA == ParentB) continue;

        if (ParentA < ParentB)
        {
            Parent[ParentB] = ParentA; 
        }
        else
        {
            Parent[ParentA] = ParentB;
        }
    }

    int Answer = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (GetParent(i) == 1) Answer++;
    }
    cout << Answer << '\n';
    
    return 0;
}