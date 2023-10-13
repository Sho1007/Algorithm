#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    for (int i = 0; i < score.size(); ++i)
    {
        if (PQ.size() < k) PQ.push(score[i]);
        else
        {
            if (PQ.top() < score[i])
            {
                PQ.pop();
                PQ.push(score[i]);
            }
            
        }
        
        answer.push_back(PQ.top());
    }
    
    return answer;
}