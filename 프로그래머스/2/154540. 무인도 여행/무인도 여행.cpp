#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<bool>> VisitVector;
vector<int> Answer;
void Visit(vector<string>& Maps, int Y, int X)
{
    //cout << "Go To " << Y << ", " << X << '\n';
    queue<pair<int,int>> PosQueue;
    
    VisitVector[Y][X] = true;
    PosQueue.push({Y, X});
    
    int Result = 0;
    
    while (!PosQueue.empty())
    {
        pair<int,int> CurrentPos = PosQueue.front(); PosQueue.pop();
        
        Result += (Maps[CurrentPos.first][CurrentPos.second]) - '0';
        //cout << CurrentPos.first << ", " << CurrentPos.second << " : " << Result << '\n';
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = CurrentPos.first + dy[i];
            int NextX = CurrentPos.second + dx[i];
            
            if (NextY < 0 || NextY >= Maps.size() || NextX < 0 || NextX >= Maps[0].size()) continue;
            if (Maps[NextY][NextX] == 'X' || VisitVector[NextY][NextX] == true) continue;
            VisitVector[NextY][NextX] = true;
            PosQueue.push({NextY, NextX});
        }
    }
    
    Answer.push_back(Result);
}

vector<int> solution(vector<string> maps) {
    
    
    VisitVector = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));
    
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] != 'X' && VisitVector[i][j] == false)
            {
                Visit(maps, i, j);
            }
        }
    }
    
    sort(Answer.begin(), Answer.end());
    
    if (Answer.size() == 0) Answer.push_back(-1);
    
    return Answer;
}