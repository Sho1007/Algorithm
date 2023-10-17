#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> MapX;
map<int, int> MapY;
vector<int> CommonVector;

string solution(string X, string Y) {
    string answer = "";
    
    for (int i = 0; i < X.size(); ++i)
    {
        MapX[X[i] - '0']++;
    }
    
    for (int i = 0; i < Y.size(); ++i)
    {
        MapY[Y[i] - '0']++;
    }
    
    for (auto Iter : MapX)
    {
        int RepeatCount = Iter.second <= MapY[Iter.first] ? Iter.second : MapY[Iter.first];

        if (RepeatCount != 0)
        {
            //cout << Iter.first << ' ' << RepeatCount << '\n';
            
            for (int i = 0; i < RepeatCount; ++i)
            {
                CommonVector.push_back(Iter.first);
            }
        }
    }
    
    if (CommonVector.size() == 0) answer = "-1";
    else if (CommonVector[0] == 0 && CommonVector.back() == 0) answer = "0";
    else
    {
        for (int i = CommonVector.size()-1; i >= 0; --i)
        {
            answer += CommonVector[i] + '0';
        }
    }
    
    
    return answer;
}