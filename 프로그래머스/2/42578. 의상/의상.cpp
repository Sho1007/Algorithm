#include <string>
#include <vector>

#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0; 
    map<string, vector<string>> m;
    
    for (int i = 0; i < clothes.size(); ++i)
    {
        m[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    if (m.size() == 1)
        answer = m.begin()->second.size();
    else
    {
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if (iter == m.begin())
                answer = iter->second.size() + 1;
            else
                answer *= (iter->second.size() + 1);
        }
        answer -= 1;
    }
    
    
    
    return answer;
}