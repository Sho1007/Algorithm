#include <iostream>
using namespace std;

int N;
unsigned long long Answer = 0;
int diceValue[6] = {};
int minValue[6] =
{
    7'000'000,
    7'000'000,
    7'000'000,
    7'000'000
};
int opposite[6] = { 5, 4, 3, 2, 1, 0 };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < 6; ++i)
    {
        cin >> diceValue[i];
    }

    for (int i = 0; i < 6; ++i)
    {
        int oneValue = diceValue[i];
        if (minValue[1] > oneValue)
        {
            minValue[1] = oneValue;
        }
        for (int j = 0; j < 6; ++j)
        {
            if (i == j || j == opposite[i]) continue;
            int twoValue = oneValue + diceValue[j];
            if (minValue[2] > twoValue)
            {
                minValue[2] = twoValue;
            }
            for (int k = 0; k < 6; ++k)
            {
                if (k == i || k == j || k == opposite[i] || k == opposite[j]) continue;
                int threeValue = twoValue + diceValue[k];
                if (minValue[3] > threeValue)
                {
                    minValue[3] = threeValue;
                }
            }
        }
    }

    if (N == 1)
    {
        int maxValue = diceValue[0];
        for (int i = 0; i < 6; ++i)
        {
            Answer += diceValue[i];
            if (maxValue < diceValue[i])
            {
                maxValue = diceValue[i];
            }
        }

        Answer -= maxValue;
    }
    else
    {
        unsigned long long Count;
        // 3개짜리
        Answer = 4 * minValue[3];
        // 2개짜리
        Count = (N - 2) * 4;
        Count += (N - 1) * 4;
        Answer += Count * minValue[2];
        // 1개짜리
        Count = (N - 2);
        Count *= Count;
        Count += (unsigned long long)(N - 1) * (N - 2) * 4;
        Answer += Count * minValue[1];
    }

    cout << Answer << '\n';

    return 0;
}