#include <iostream>
#include <vector>

using namespace std;

int V, E;

vector<vector<int>> vec;
vector<bool> visited;

int Dfs(int here)
{
    visited[here] = true;
    int sum = 1;

    for (int there : vec[here])
    {
        if (!visited[there])
            sum += Dfs(there);
    }

    return sum;
}

int main()
{
    scanf("%d %d", &V, &E);

    vec = vector<vector<int>>(V);
    visited = vector<bool>(V, false);

    int v1, v2;
    for (; E > 0; --E)
    {
        scanf("%d %d", &v1, &v2);
        v1--;
        v2--;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }

    cout << Dfs(0) - 1 << endl;

    return 0;
}