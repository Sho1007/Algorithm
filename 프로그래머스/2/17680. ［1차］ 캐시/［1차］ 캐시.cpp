#include <string>
#include <vector>
#include <queue>
//#include <iostream>
#include <algorithm>
using namespace std;

vector<string> CacheVector;

bool CacheHit(string& Target)
{
    for (int i = 0; i < CacheVector.size(); ++i)
    {
        if (CacheVector[i] == Target)
        {
            CacheVector.push_back(CacheVector[i]);
            CacheVector.erase(CacheVector.begin() + i);
            
            return true;
        }
    }
    
    return false;
}

void LRU()
{
    CacheVector.erase(CacheVector.begin());
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for (int i = 0; i < cities.size(); ++i)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        //cout << cities[i] << " : ";
        if (CacheHit(cities[i]))
        {
            //cout << "Hitted\n";
            answer++;
        }
        else
        {
            //cout << "Missed\n";
            answer += 5;
            CacheVector.push_back(cities[i]);
            if (CacheVector.size() > cacheSize) LRU();
        }
    }
    
    return answer;
}