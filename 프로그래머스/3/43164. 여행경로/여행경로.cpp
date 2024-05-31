#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> adjMap;
unordered_map<string, int> indexMap;
vector<pair<string,string>> stringVector;

queue<vector<string>> pathQueue;

int ticketSize;

vector<string> answer;

void BT(vector<string>& currentPath)
{
    if (currentPath.size() == ticketSize + 1)
    {
        if (answer.empty()) answer = currentPath;
        else if (answer > currentPath) answer = currentPath;
        
        return;
    }
    
    string currentPos = currentPath.back();
    
    for (int i = 0; i < adjMap[currentPos].size(); ++i)
    {
        currentPath.push_back(adjMap[currentPos][i]);
        adjMap[currentPos].erase(adjMap[currentPos].begin() + i);
        BT(currentPath);
        adjMap[currentPos].insert(adjMap[currentPos].begin() + i, currentPath.back());
        currentPath.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    ticketSize = tickets.size();
    
    for (int i = 0; i < tickets.size(); ++i)
    {
        adjMap[tickets[i][0]].push_back(tickets[i][1]);
        indexMap[tickets[i][0]+tickets[i][1]] = i;
        stringVector.push_back({tickets[i][0],tickets[i][1]});
    }
    
    for (int i = 0; i < adjMap["ICN"].size(); ++i)
    {
        vector<string> currentPath = { "ICN", adjMap["ICN"][i] };    
        adjMap["ICN"].erase(adjMap["ICN"].begin() + i);
        BT(currentPath);
        adjMap["ICN"].insert(adjMap["ICN"].begin() + i, currentPath.back());
    }
    
    
    
//     for (int i = 0; i < adjMap["ICN"].size(); ++i)
//     {
//         unordered_map<string, int> pathMap;
//         pathMap["ICN" + adjMap["ICN"][i]] = 0;
        
//         queue<pair<string, unordered_map<string, int>>> pathQueue;
//         pathQueue.push({adjMap["ICN"][i], pathMap});
        
//         while (pathQueue.empty() == false)
//         {
//             pair<string, unordered_map<string, int>> currentPath = pathQueue.front(); pathQueue.pop();
            
            
            
//             if (currentPath.second.size() == tickets.size())
//             {
//                 vector<pair<string, int>> vec(currentPath.second.begin(), currentPath.second.end());
//                 sort(vec.begin(), vec.end(), [](pair<string,int>& A, pair<string,int>& B)->bool
//                      {
//                          return A.second < B.second;
//                      });
                
//                 vector<string> newPath(tickets.size() + 1);
//                 newPath[0] = "ICN";
                
//                 for (int i = 0; i < vec.size(); ++i)
//                 {
//                     newPath[i+1] = vec[i].first.substr(3);
//                 }
                
//                 if (answer.empty()) answer = newPath;
//                 else if (answer > newPath) answer = newPath; 
//                 continue;
//             }
            
//             for (int i = 0; i < adjMap[currentPath.first].size(); ++i)
//             {
//                 if (currentPath.second.find(currentPath.first + adjMap[currentPath.first][i]) != currentPath.second.end()) continue;
//                 unordered_map<string, int> newPathMap(currentPath.second);
//                 newPathMap[currentPath.first + adjMap[currentPath.first][i]] = currentPath.second.size();
//                 pathQueue.push({adjMap[currentPath.first][i], newPathMap});
//             }
//         }
//     }
        
    return answer;
}