#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int N, M, A, B, C;

pair<pair<int, int>, int>* arr;

void BF()
{
    vector<long long> dist(N+1, INF);
    dist[1] = 0;

    bool isNeg = false;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (dist[arr[j].first.first] == INF) continue;
            if (dist[arr[j].first.second] > dist[arr[j].first.first] + arr[j].second)
            {
                if (i == N - 1)
                {
                    isNeg = true;
                    break;
                }
                dist[arr[j].first.second] = dist[arr[j].first.first] + arr[j].second;
            }
        }
    }

    if (isNeg) cout << "-1\n";
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            if (dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr = new pair<pair<int, int>, int>[M];
    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        arr[i] = { {A, B}, C };
    }
    BF();
    delete[] arr;
    return 0;
}