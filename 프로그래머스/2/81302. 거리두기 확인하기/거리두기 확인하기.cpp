#include <string>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool CheckIsTooClose(vector<string>& Vector, int StartX, int StartY)
{
    bool Visit[5][5] = {};
    int Cost[5][5] = {};
    queue<pair<int,int>> Queue;
    Queue.push({StartX, StartY});
    Visit[StartX][StartY] = true;
    
    while (Queue.empty() == false)
    {
        pair<int,int> Current = Queue.front(); Queue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int NextX = Current.first + dx[i];
            int NextY = Current.second + dy[i];
            
            if (NextX < 0 || NextX >= 5 || NextY < 0 || NextY >= 5) continue;
            if (Visit[NextX][NextY] == true || Vector[NextX][NextY] == 'X') continue;
            
            Visit[NextX][NextY] = true;
            Cost[NextX][NextY] = Cost[Current.first][Current.second] + 1;
            
            
            if (Vector[NextX][NextY] == 'P')
            {
                return true;
            }
            
            if (Cost[NextX][NextY] < 2)
            {
                Queue.push({NextX, NextY});
            }
        }
    }
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
        
    for (vector<string>& Vector : places)
    {
        bool bIsTooClose = false;
        for (int i = 0; i < Vector.size(); ++i)
        {
            for (int j = 0; j < Vector[i].size(); ++j)
            {
                if (Vector[i][j] == 'P')
                {
                    if (CheckIsTooClose(Vector, i, j))
                    {
                        bIsTooClose = true;
                        break;
                    }
                }
            }
        }
        
        
        if (bIsTooClose)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(1);
        }
    }
        
    return answer;
}