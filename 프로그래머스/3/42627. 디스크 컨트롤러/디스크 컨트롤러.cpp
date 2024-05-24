#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Cmp
{
    bool operator()(vector<int>& A, vector<int>& B)
    {
        return A[1] > B[1];
    }
};

int currentTime = 0;
int currentIndex = 0;
priority_queue<vector<int>, vector<vector<int>>, Cmp> PQ;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end(), [](vector<int>& A, vector<int>& B)->bool{
        return A[0] < B[0];
    });
    
    do
    {
        if (PQ.empty() && currentTime < jobs[currentIndex][0])
        {
            currentTime = jobs[currentIndex][0];
        }
        
        for (; currentIndex < jobs.size();)
        {
            // cout << "   " << jobs[currentIndex][0] << ' ' << currentTime << '\n';
            if (jobs[currentIndex][0] <= currentTime)
            {
                PQ.push(jobs[currentIndex++]);
            }
            else break;
        }
        
        // cout << PQ.size() << '\n';
        vector<int> currentJob = PQ.top(); PQ.pop();
        
        // cout << currentTime << ' ' << currentJob[0] << ' ' << currentJob[1] << '\n';
        
        currentTime += currentJob[1];
        answer += currentTime - currentJob[0];
        
        //cout << currentTime << ' ' << currentJob[0] << ' ' << currentJob[1] << '\n';
        
    } while (PQ.empty() == false || currentIndex < jobs.size());
    
    answer /= jobs.size();
    
    return answer;
}