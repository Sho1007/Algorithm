#include <iostream>
#include <vector>
#include <queue>
#define INF 987'654'321
using namespace std;

vector<vector<int>> Connected;
vector<int> Cost;
queue<int> Queue;
int N, M, A, B, Current, Next;
int Answer, SameCost;

void BFS()
{
    Cost[0] = 0;

    Queue.push(0);

    while (Queue.empty() == false)
    {
        Current = Queue.front(); Queue.pop();

        for (int i = 0; i < Connected[Current].size(); ++i)
        {
            Next = Connected[Current][i];

            if (Cost[Next] <= Cost[Current] + 1)
            {
                continue;
            }
            Cost[Next] = Cost[Current] + 1;
            Queue.push(Next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    Connected = vector<vector<int>>(N, vector<int>());
    Cost = vector<int>(N, INF);

    while (M-- > 0)
    {
        cin >> A >> B;
        Connected[A - 1].push_back(B - 1);
        Connected[B - 1].push_back(A - 1);
    }

    BFS();

    Answer = 1;
    SameCost = 1;

    for (int i = 2; i < N; ++i)
    {
        if (Cost[Answer] > Cost[i])
        {
            continue;
        }
        else if (Cost[Answer] == Cost[i])
        {
            SameCost++;
        }
        else
        {
            Answer = i;
            SameCost = 1;
        }
    }

    cout << Answer + 1 << ' ' << Cost[Answer] << ' ' << SameCost << '\n';

    return 0;
}