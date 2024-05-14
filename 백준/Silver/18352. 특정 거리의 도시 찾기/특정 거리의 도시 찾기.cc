#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N, M, K, X, A, B;

map<int, vector<int>> adjMap;
queue<int> Queue;
vector<int> DistVector;

// 다익스트라
// N * N 배열에 저장하기엔 도시가 너무 많음
// -> 인접 노드를 저장할 벡터 (거리는 1임)

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> X;

    DistVector = vector<int>(N + 1, -1);

    while (M-->0)
    {
        cin >> A >> B;

        adjMap[A].push_back(B);
    }

    DistVector[X] = 0;
    
    for (int i = 0; i < adjMap[X].size(); ++i)
    {
        DistVector[adjMap[X][i]] = 1;
        Queue.push(adjMap[X][i]);
    }

    while (Queue.empty() == false)
    {
        int Current = Queue.front(); Queue.pop();

        for (int i : adjMap[Current])
        {
            if (DistVector[i] == -1 || DistVector[i] > DistVector[Current] + 1)
            {
                DistVector[i] = DistVector[Current] + 1;

                Queue.push(i);
            }
        }
    }

    bool bIsFound = false;
    for (int i = 1; i < DistVector.size(); ++i)
    {
        if (DistVector[i] == K)
        {
            bIsFound = true;
            cout << i << '\n';
        }
    }

    if (bIsFound == false)
    {
        cout << "-1\n";
    }
    
    return 0;
}