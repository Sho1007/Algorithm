#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> StartToLever;
vector<vector<int>> LeverToEnd;

int solution(vector<string> maps) {
    int answer = 0;
    
    StartToLever = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1));
    LeverToEnd = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), -1));
    
    pair<int,int> StartPos;
    pair<int,int> EndPos;
    pair<int,int> LeverPos;
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'S')
            {
                StartPos = {i, j};
            }
            else if (maps[i][j] == 'E')
            {
                EndPos = {i, j};
            }
            else if (maps[i][j] == 'L')
            {
                LeverPos = {i, j};
            }
        }
    }
    
    StartToLever[StartPos.first][StartPos.second] = 0;
    {
        queue<pair<int,int>> Queue;   
        
        Queue.push(StartPos);
        
        while (Queue.empty() == false)
        {
            pair<int,int> Current = Queue.front(); Queue.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int NextY = Current.first + dy[i];
                int NextX = Current.second + dx[i];
                
                if (NextY < 0 || NextY >= maps.size() || NextX < 0 || NextX >= maps[0].size()) continue;
                if (maps[NextY][NextX] == 'X') continue;
                
                if (StartToLever[NextY][NextX] == -1 || StartToLever[NextY][NextX] > StartToLever[Current.first][Current.second] + 1)
                {
                    StartToLever[NextY][NextX] = StartToLever[Current.first][Current.second] + 1;
                    Queue.push({NextY, NextX});
                }
            }
        }
    }
    
    if (StartToLever[LeverPos.first][LeverPos.second] == -1) return -1;
    
    answer += StartToLever[LeverPos.first][LeverPos.second];
    
    LeverToEnd[LeverPos.first][LeverPos.second] = 0;
    
    {
        queue<pair<int,int>> Queue;   
        
        Queue.push(LeverPos);
        
        while (Queue.empty() == false)
        {
            pair<int,int> Current = Queue.front(); Queue.pop();
            
            for (int i = 0; i < 4; ++i)
            {
                int NextY = Current.first + dy[i];
                int NextX = Current.second + dx[i];
                
                if (NextY < 0 || NextY >= maps.size() || NextX < 0 || NextX >= maps[0].size()) continue;
                if (maps[NextY][NextX] == 'X') continue;
                
                if (LeverToEnd[NextY][NextX] == -1 || LeverToEnd[NextY][NextX] > LeverToEnd[Current.first][Current.second] + 1)
                {
                    LeverToEnd[NextY][NextX] = LeverToEnd[Current.first][Current.second] + 1;
                    Queue.push({NextY, NextX});
                }
            }
        }
    }
    
    if (LeverToEnd[EndPos.first][EndPos.second] == -1) return -1;
        
    answer += LeverToEnd[EndPos.first][EndPos.second];
    
    return answer;
}