#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int start = 0;
    
    
    while (start != progresses.size())
    {
        for (int i = start; i < progresses.size(); ++i)
            progresses[i] += speeds[i];
        
        if (progresses[start] >= 100)
        {
            int count = 0;
            for (int i = start; i < progresses.size(); ++i)
            {
                if (progresses[i] >= 100)
                {
                    count++;
                    start = i + 1;
                }
                else
                    break;
            }
            
            answer.push_back(count);
        }
    }
    
    
    return answer;
}