#include <iostream>
#include <string>
#include <map>
using namespace std;

string Name;
map<char, int> Map;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> Name;

    for (int i = 0; i < Name.length(); ++i)
    {
        Map[Name[i]]++;
    }

    string Answer = "";
    for (pair<const char, int>& Iter : Map)
    {
        if (Iter.second % 2 == 1)
        {
            if (Answer.length() == 1)
            {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            Answer += Iter.first;
            Iter.second--;
        }
    }
    if (Map[Answer[0]] == 0)
    {
        Map.erase(Answer[0]);
    }

    for (auto Iter = Map.rbegin(); Iter != Map.rend(); Iter++)
    {
        while (Iter->second > 0)
        {
            Iter->second -= 2;
            Answer = Iter->first + Answer + Iter->first;
        }
    }

    cout << Answer << '\n';
    
    return 0;
}