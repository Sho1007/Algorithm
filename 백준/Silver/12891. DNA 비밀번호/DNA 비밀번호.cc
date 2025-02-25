#include <iostream>
#include <string>
#include <map>
using namespace std;

int S, P, Answer = 0;
map<char, int> Map = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
int Count[4] = {};
int Target[4] = {};
string String;

int CurrentLength = 0;

bool CheckCanUse()
{
    bool CanUse = true;
    for (int j = 0; j < 4; ++j)
    {
        if (Count[j] < Target[j])
        {
            CanUse = false;
            break;
        }
    }

    return CanUse;
}

int main()
{
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> S >> P;
    cin >> String;

    for (int i = 0; i < 4; ++i)
    {
        cin >> Target[i];
    }

    for (int i = 0; i < String.size(); ++i)
    {
        Count[Map[String[i]]]++;

        

        if (CurrentLength == P)
        {
            Count[Map[String[i - P]]]--;

            if (CheckCanUse())
            {
                Answer++;
            }
        }
        else if (CurrentLength < P)
        {
            CurrentLength++;

            if (CurrentLength == P)
            {
                if (CheckCanUse())
                {
                    Answer++;
                }
            }
        }
    }

    cout << Answer << '\n';

    return 0;
}