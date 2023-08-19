#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> V;
vector<int> Target;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    V = vector<int>(N);
    Target = vector<int>(M);

    for (int i = 0; i < N; ++i)
    {
        V[i] = i + 1;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> Target[i];
    }

    int Front = 0;
    int NowPos = 0;
    int Answer = 0;

    while (NowPos < Target.size())
    {
        if (V[Front] == Target[NowPos])
        {
            NowPos++;
            V.erase(V.begin() + Front);
            if (Front == V.size()) Front = 0;
        }
        else
        {
            int i;
            for (i = 1; i < V.size(); ++i)
            {
                if (V[(Front + i) % V.size()] == Target[NowPos])
                {
                    Front = (Front + i) % V.size();
                    break;
                }
                else if (V[(Front - i + V.size()) % V.size()] == Target[NowPos])
                {
                    Front = (Front - i + V.size()) % V.size();
                    break;
                }
            }
            Answer += i;
        }
    }

    cout << Answer << '\n';

    return 0;
}