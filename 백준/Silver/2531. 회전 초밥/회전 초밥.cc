#include <iostream>
using namespace std;

int N; // 놓인 접시 수
int d; // 초밥의 가짓수
int k; // 연속해서 먹는 접시의 수
int c; // 쿠폰 번호

int Dishes[30'001] = {};
int Count[30'001] = {};

int Answer = 0;
int Current = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N + k; ++i)
    {
        if (i >= k && --Count[Dishes[i - k]] == 0)
        {
            Current--;
        }

        if (i < N)
        {
            cin >> Dishes[i];
        }

        int ConvertIndex = i % N;

        Count[Dishes[ConvertIndex]]++;
        if (Count[Dishes[ConvertIndex]] == 1)
        {
            Current++;

            if (Current + (Count[c] == 0 ? 1 : 0) > Answer)
            {
                Answer = Current + (Count[c] == 0 ? 1 : 0);
            }
        }
    }

    cout << Answer << '\n';

    return 0;
}