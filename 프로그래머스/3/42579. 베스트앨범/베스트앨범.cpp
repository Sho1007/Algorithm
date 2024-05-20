#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> genresPlayCount;
map<string, vector<pair<int,int>>> indexMap;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < plays.size(); ++i)
    {
        genresPlayCount[genres[i]] += plays[i];
        indexMap[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string,int>> genresPlayCountVector(genresPlayCount.begin(), genresPlayCount.end());
    sort(genresPlayCountVector.begin(), genresPlayCountVector.end(), [](pair<string, int>& A, pair<string, int>& B)->bool{
        return A.second > B.second;
    });
    
    for (int i = 0; i < genresPlayCountVector.size(); ++i)
    {
        vector<pair<int, int>>& indexVector = indexMap[genresPlayCountVector[i].first];
        sort(indexVector.begin(), indexVector.end(), [](pair<int, int>& A, pair<int, int>& B)->bool
             {
                 if (A.second == B.second)
                 {
                     return A.first < B.first;
                 }
                 
                 return A.second > B.second;
             });
        
        answer.push_back(indexVector[0].first);
        if (indexVector.size() > 1)
        {
            answer.push_back(indexVector[1].first);
        }
    }
    
    return answer;
}