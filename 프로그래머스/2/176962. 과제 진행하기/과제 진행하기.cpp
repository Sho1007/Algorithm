#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

stack<vector<string>> Stack;

string GetEndTime(string& currentStartTime, string& currentPlayTime)
{
    int hour = stoi(currentStartTime.substr(0, 2));
    int minSum = stoi(currentStartTime.substr(3)) + stoi(currentPlayTime);
    
    if (minSum >= 60)
    {
        hour += minSum / 60;
        minSum %= 60;
    }
    
    string hourString = to_string(hour); if (hour < 10) hourString = '0' + hourString;
    string minString = to_string(minSum); if (minSum < 10) minString = '0' + minString;
    
    return hourString + ':' + minString;
}

string GetRemainTime(string& currentTime, string& nextTime)
{
    int currentIntTime = stoi(currentTime.substr(0, 2)) * 60 + stoi(currentTime.substr(3));
    int nextIntTime = stoi(nextTime.substr(0, 2)) * 60 + stoi(nextTime.substr(3));
    
    return to_string(nextIntTime - currentIntTime);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    // 시작 시간 순으로 정렬
    sort(plans.begin(), plans.end(), [](vector<string>& A, vector<string>& B)->bool
         {
             return A[1] < B[1];
         });
    
    string currentTime = "00:00";
    
    for (int i = 0; i < plans.size()-1; ++i)
    {
        string nextStartTime = plans[i+1][1];
        Stack.push(plans[i]);
        while (Stack.empty() == false)
        {
            vector<string> currentPlan = Stack.top(); Stack.pop();
            string currentStartTime = currentPlan[1];
            if (currentTime < currentStartTime) currentTime = currentStartTime;
            string currentPlayTime = currentPlan[2];
            
            string currentEndTime = GetEndTime(currentTime, currentPlayTime);
            if (currentEndTime <= nextStartTime)
            {
                currentTime = currentEndTime;
                answer.push_back(currentPlan[0]);
            }
            else
            {
                // 일의 진행 상황을 저장해야함
                // 얼마나 진행됐는가를 계산
                string remainTime = GetRemainTime(currentTime, nextStartTime);
                // playTime 에서 remainTime 을 뺌
                currentPlayTime = to_string(stoi(currentPlayTime) - stoi(remainTime));
                currentPlan[2] = currentPlayTime;
                Stack.push(currentPlan);
                
                break;
            }
        }
        
        // 현재 시작 시간 + 과제 시간이 다음 과제의 시작 시간보다 큰 경우 스택에 push
    }
    
    answer.push_back(plans[plans.size()-1][0]);
    
    while (Stack.empty() == false)
    {
        answer.push_back(Stack.top()[0]); Stack.pop();
    }
    
    return answer;
}