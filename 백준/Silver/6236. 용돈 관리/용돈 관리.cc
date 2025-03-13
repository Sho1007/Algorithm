#include <iostream>
#include <vector>
using namespace std;
inline int MAX(int A, int B) { return A > B ? A : B; }

int N, M, Left, Right, Mid, Answer;
int SpendSum = 0;

vector<int> Spend;

bool Check()
{
    int WithdrawCount = 0;
    int CurrentMoney = 0;
    for (int i = 0; i < N; ++i)
    {
        if (CurrentMoney < Spend[i])
        {
            WithdrawCount++;
            CurrentMoney = Mid;
            if (WithdrawCount > M || CurrentMoney < Spend[i])
            {
                return false;
            }
        }
        CurrentMoney -= Spend[i];
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    Spend = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Spend[i];
        SpendSum += Spend[i];
    }

    Left = 1;
    Right = SpendSum;

    while (Left <= Right )
    {
        Mid = (Left + Right) / 2;
        if (Check())
        {
            Answer = Mid;
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }

    cout << Answer << '\n';

    return 0;
}