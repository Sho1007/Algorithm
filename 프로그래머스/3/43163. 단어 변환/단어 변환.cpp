#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#define MAX 51

using namespace std;

unordered_map<string, vector<string>> adjMap;
unordered_map<string, bool> visitedMap;
string Target;
int answer = MAX;

bool CheckIsSimilar(string& A, string& B)
{
    int difCount = 0;
    for (int i = 0; i < A.length(); ++i)
    {
        if (A[i] != B[i])
        {
            difCount++;
            if (difCount > 1) return false;
        }
    }
    
    return difCount == 1;
}

void DFS(vector<string>& path)
{
    if (path.back() == Target)
    {
        if (path.size() < answer) answer = path.size();
        
        return;
    }
    
    for (int i = 0; i < adjMap[path.back()].size(); ++i)
    {
        
        if (visitedMap[adjMap[path.back()][i]]) continue;
        
        visitedMap[adjMap[path.back()][i]] = true;
        path.push_back(adjMap[path.back()][i]);
        DFS(path);
        path.pop_back();
        visitedMap[adjMap[path.back()][i]] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    Target = target;
    
    words.push_back(begin);
    
    for (int i = 0; i < words.size(); ++i)
    {
        visitedMap[words[i]] = false;
        for (int j = i + 1; j < words.size(); ++j)
        {
            if (CheckIsSimilar(words[i], words[j]))
            {
                adjMap[words[i]].push_back(words[j]);
                adjMap[words[j]].push_back(words[i]);
            }
        }
    }
    
    visitedMap[begin] = true;
    vector<string> path = {begin};
    DFS(path);
    
    return (answer == MAX ? 0 : answer - 1);
}