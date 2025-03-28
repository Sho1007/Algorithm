#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int T, N, Answer;

vector<string> Array;
char MBTI[4][2] = {
    {'E', 'I'},
    {'N', 'S'},
    {'F', 'T'},
    {'P', 'J'}}
;
vector<string> MBTIArray = { "" };

map<string, map<string, int>> DistanceMap;

vector<string> operator+ (vector<string> A, string B)
{
    A.push_back(B);
    return A;
}

void BT(int StartPos, vector<string> Target)
{
    if (Target.size() == 3)
    {
        int CurrentDistance = 0;
        CurrentDistance += DistanceMap[Target[0]][Target[1]];
        CurrentDistance += DistanceMap[Target[1]][Target[2]];
        CurrentDistance += DistanceMap[Target[0]][Target[2]];

        if (CurrentDistance < Answer)
        {
            Answer = CurrentDistance;
        }

        return;
    }

    for (int i = StartPos; i < N; ++i)
    {
        BT(i + 1, Target + Array[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 4; ++i)
    {
        vector<string> newMBTIArray;
        for (int j = 0; j < 2; ++j)
        {
            for (const string& Iter : MBTIArray)
            {
                newMBTIArray.push_back(Iter + MBTI[i][j]);
            }
        }

        MBTIArray = newMBTIArray;
    }

    for(string& First : MBTIArray)
    {
        for (string& Second : MBTIArray)
        {
            int Distance = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (First[i] != Second[i])
                {
                    Distance++;
                }
            }

            DistanceMap[First][Second] = Distance;
        }
    }

    cin >> T;

    while (T-- > 0)
    {
        cin >> N;
        Array = vector<string>(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> Array[i];
        }
        
        if (N <= 32)
        {
            Answer = 987'654'321;
            BT(0, {});
        }
        else
        {
            Answer = 0;
        }

        cout << Answer << '\n';
    }

    return 0;
}