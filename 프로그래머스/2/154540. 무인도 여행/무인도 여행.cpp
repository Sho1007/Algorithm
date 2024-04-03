#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> Visit;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int BFS(int Y, int X, const vector<string>& maps)
{
    queue<pair<int,int>> Queue;
    
    Visit[Y][X] = true;
    int Day = maps[Y][X] - '0';
    Queue.push({Y,X});
    
    while(Queue.empty() == false)
    {
        pair<int,int> Current = Queue.front(); Queue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = Current.first + dy[i];
            int NextX = Current.second + dx[i];
            
            if (NextY < 0 || NextY >= maps.size() || NextX < 0 || NextX >= maps[0].length()) continue;
            if (maps[NextY][NextX] == 'X' || Visit[NextY][NextX] == true) continue;
            
            Visit[NextY][NextX] = true;
            Day += maps[NextY][NextX] - '0';
            Queue.push({NextY,NextX});
        }
    }
    
    return Day;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    Visit = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].length(), false));
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].length(); ++j)
        {
            if (maps[i][j] != 'X' && Visit[i][j] == false)
            {
                answer.push_back(BFS(i, j, maps));
            }
        }
    }
    
    
    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}