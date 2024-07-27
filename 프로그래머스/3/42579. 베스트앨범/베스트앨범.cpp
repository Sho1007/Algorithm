#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>


using namespace std;

unordered_map<string,int> genrePlayCountMap;
vector<pair<string,int>> genrePlayCountVector;
unordered_map<string, vector<pair<int,int>>> genreMap;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); ++i)
    {
        genrePlayCountMap[genres[i]] += plays[i];
        genreMap[genres[i]].push_back({i, plays[i]});
    }
    
    for (auto& genreIter : genreMap)
    {
        vector<pair<int,int>>& genreVector = genreIter.second;
        sort(genreVector.begin(), genreVector.end(), [](pair<int,int>& A, pair<int,int>& B)->bool
             {
                 if (A.second == B.second)
                 {
                     return A.first < B.first;
                 }
                 
                 return A.second > B.second;
             });
    }
    
    genrePlayCountVector = vector<pair<string,int>>(genrePlayCountMap.begin(), genrePlayCountMap.end());
    sort(genrePlayCountVector.begin(), genrePlayCountVector.end(), [](pair<string,int>& A, pair<string,int>& B)->bool
         {
             return A.second > B.second;
         });
    
    for (const auto& genre : genrePlayCountVector)
    {
        answer.push_back(genreMap[genre.first][0].first);
        if (genreMap[genre.first].size() > 1)
        {
            answer.push_back(genreMap[genre.first][1].first);
        }
    }
    
    return answer;
}