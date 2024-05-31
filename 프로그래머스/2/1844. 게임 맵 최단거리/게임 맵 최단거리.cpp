#include <queue>
#include <iostream>
#define MAX 987'654'321
using namespace std;

int dX[4] = {-1, 1, 0, 0};
int dY[4] = {0, 0, -1, 1};

vector<vector<int>> costMap;

void PrintCost()
{
    for (int i = 0; i < costMap.size(); ++i)
    {
        for (int j = 0; j < costMap[i].size(); ++j)
        {
            cout << costMap[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
}

void BFS(vector<vector<int>>& maps)
{
    queue<pair<int,int>> posQueue;
    posQueue.push({0, 0});
    costMap[0][0] = 1;
    
    while (posQueue.empty() == false)
    {
        pair<int,int> currentPos = posQueue.front(); posQueue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextX = currentPos.first + dX[i];
            int nextY = currentPos.second + dY[i];
            
            if (nextX < 0 || nextX >= maps.size() || nextY < 0 || nextY >= maps[0].size()) continue;
            if (maps[nextX][nextY] == 0 || costMap[nextX][nextY] <= costMap[currentPos.first][currentPos.second] + 1) continue;
            costMap[nextX][nextY] = costMap[currentPos.first][currentPos.second] + 1;
            posQueue.push({nextX, nextY});
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    costMap = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), MAX));
    
    BFS(maps);
    
    // PrintCost();
    
    return costMap.back().back() == MAX ? -1 : costMap.back().back();
}