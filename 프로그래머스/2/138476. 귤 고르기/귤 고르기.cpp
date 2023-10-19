#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<int, int> CountMap;
vector<pair<int,int>> SortVector;
int CurrentCount = 0;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int i = 0; i < tangerine.size(); ++i)
    {
        CountMap[tangerine[i]]++;
    }
    
    SortVector = vector<pair<int,int>>(CountMap.begin(), CountMap.end());
    
    sort(SortVector.begin(), SortVector.end(), [](pair<int,int> A, pair<int,int> B)->bool
         {
            return A.second > B.second;
         });
    
    for (int i = 0; i < SortVector.size(); ++i)
    {
        answer++;
        CurrentCount += SortVector[i].second;
        if (CurrentCount >= k) break;
    }
    
    return answer;
}