#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> CarNumberMap;
int N, CarNum = 0, CheckIndex = 0, Answer = 0;
vector<bool> IsAlreadyExit;
string Input;
vector<string> Enters;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    IsAlreadyExit = vector<bool>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        CarNumberMap[Input] = CarNum++;
        Enters.push_back(Input);
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        CarNum = CarNumberMap[Input];

        while (CheckIndex < N && IsAlreadyExit[CarNumberMap[Enters[CheckIndex]]])
        {
            CheckIndex++;
        }

        if (CarNum == CarNumberMap[Enters[CheckIndex]])
        {
            CheckIndex++;
        }
        else
        {
            Answer++;
        }
        IsAlreadyExit[CarNum] = true;
    }

    cout << Answer << '\n';

    return 0;
}