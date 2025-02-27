#include <iostream>
using namespace std;

int N, Pos, Answer = 0;
int Board[1'001] = {};
int Left[1'001] = {};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Pos;
        cin >> Board[Pos];
    }

    int MaxLength = 0;

    for (int i = 1; i <= 1000; ++i)
    {
        if (Board[i] > MaxLength)
        {
            MaxLength = Board[i];
        }
        Left[i] = MaxLength;
    }

    MaxLength = 0;
    for (int i = 1'000; i > 0; --i)
    {
        if (Board[i] > MaxLength)
        {
            MaxLength = Board[i];
        }

        Answer += MaxLength < Left[i] ? MaxLength : Left[i];
    }

    cout << Answer << '\n';

    return 0;
}