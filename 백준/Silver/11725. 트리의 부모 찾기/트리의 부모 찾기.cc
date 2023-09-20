#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N;
struct Node
{
    int data;
    int p = 0;
    int c = 0;
    vector<int> adj;
};

Node arr[100'001] = {};

void Union(Node& a, Node& b)
{
    if (!a.p && !b.p)
    {
        a.adj.push_back(b.data);
        b.adj.push_back(a.data);
    }
    else
    {
        if (a.p)
        {
            b.p = a.data;
            // b의 adj중 a가 아닌 것들 다 Union
            for (int i = 0; i < b.adj.size(); ++i)
            {
                if (b.adj[i] == a.data) continue;
                Union(b, arr[b.adj[i]]);
            }
        }
        else
        {
            a.p = b.data;
            // a의 adj중 b가 아닌 것들 다 Union
            for (int i = 0; i < a.adj.size(); ++i)
            {
                if (a.adj[i] == b.data) continue;
                Union(a, arr[a.adj[i]]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        arr[i].data = i;
    }
    arr[1].p = 1;

    int A, B;
    for (int i = 1; i < N; ++i)
    {
        cin >> A >> B;
        Union(arr[A], arr[B]);
    }

    for (int i = 2; i <= N; ++i)
    {
        cout << arr[i].p << endl;
    }

    return 0;
}