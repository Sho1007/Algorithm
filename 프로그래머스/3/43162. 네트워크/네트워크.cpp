#include <string>
#include <queue>
#include <iostream>

using namespace std;

vector<bool> visited;

void BFS(vector<vector<int>>& computers, int startPos)
{
    queue<int> posQueue;
    posQueue.push(startPos);
    visited[startPos] = true;
    
    while (posQueue.empty() == false)
    {
        
        int currentPos = posQueue.front(); posQueue.pop();
        // cout << "   " << currentPos << '\n'; 
        for (int i = 0; i < computers[currentPos].size(); ++i)
        {
            if (currentPos == i) continue;
            if (computers[currentPos][i] == 1 && visited[i] == false)
            {
                posQueue.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
        {
            // cout << i << '\n';
            answer++;
            BFS(computers, i);
        }
    }
    
    return answer;
}