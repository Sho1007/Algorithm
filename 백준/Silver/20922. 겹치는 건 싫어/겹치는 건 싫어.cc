#include <iostream>
#include <map>
using namespace std;

int N, K, StartPos = 0, CurrentLength = 0, MaxLength = 0;
int Array[200'001] = {};
int Count[100'001] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
    }

    for (int i = 0; i < N; ++i)
    {
        if (++Count[Array[i]] > K)
        {
            for (; StartPos < i; ++StartPos)
            {
                Count[Array[StartPos]]--;
                if (Array[StartPos] == Array[i])
                {
                    StartPos++;
                    break;
                }
            }

            CurrentLength = i - StartPos + 1;
        }
        else
        {
            CurrentLength++;
        }

        if (MaxLength < CurrentLength)
        {
            MaxLength = CurrentLength;
        }
    }

    cout << MaxLength << '\n';

    return 0;
}