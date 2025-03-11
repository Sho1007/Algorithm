#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ABS(int A) { return A > 0 ? A : -A; }

int T, N, Left, Right, Answer = 0;
vector<int> V;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while (T-- > 0)
    {
        cin >> N;
        V = vector<int>(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> V[i];
        }
        sort(V.begin(), V.end());

        bool IsFront = true;
        Answer = 0;
        Left = Right = V[N - 1];

        for (int i = N - 2; i >= 0; --i)
        {
            if (IsFront)
            {
                if (Answer < Left - V[i])
                {
                    //cout << "Left : " << Left << ", Prev : " << V[i] << '\n';
                    Answer = Left - V[i];
                }
                Left = V[i];
            }
            else
            {
                if (Answer < Right - V[i])
                {
                    //cout << "Right : " << Right << ", Prev : " << V[i] << '\n';

                    Answer = Right - V[i];
                }
                Right = V[i];
            }

            IsFront = !IsFront;
        }

        if (Answer < ABS(Left - Right))
        {
            Answer = ABS(Left - Right);
        }

        cout << Answer << '\n';
    }

    return 0;
}