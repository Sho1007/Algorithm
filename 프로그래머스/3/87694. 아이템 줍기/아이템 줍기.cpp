#include <string>
#include <queue>
#include <iostream>

using namespace std;

int dX[4] = {0, 0, -1, 1};
int dY[4] = {-1, 1, 0, 0};
bool map[101][101] = {};
vector<vector<int>> costMap;

void PrintMap()
{
    for (int i = 1; i < 21; ++i)
    {
        for (int j = 1; j < 21; ++j)
        {
            cout << costMap[i][j] << "  ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void BFS(int x, int y)
{
    queue<pair<int,int>> posQueue;
    posQueue.push({x, y});
    costMap[x][y] = 0;
    
    while (posQueue.empty() == false)
    {
        pair<int,int> currentPos = posQueue.front(); posQueue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextX = currentPos.first + dX[i];
            int nextY = currentPos.second + dY[i];
            
            if (nextX < 0 || nextX >= 101 || nextY < 0 || nextY >= 101) continue;
            if (map[nextX][nextY] == false || (costMap[nextX][nextY] != -1 && costMap[nextX][nextY] <= costMap[currentPos.first][currentPos.second] + 1)) continue;
            
            costMap[nextX][nextY] = costMap[currentPos.first][currentPos.second] + 1;
            posQueue.push({nextX, nextY});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    costMap = vector<vector<int>>(101, vector<int>(101, -1));
    
    for (auto& iter : rectangle)
    {
        for (int i = 0; i < 4; ++i)
        {
            iter[i] *= 2;
        }
        
        for (int i = iter[0]; i <= iter[2]; ++i)
        {
            map[i][iter[1]] = true;
            map[i][iter[3]] = true;
        }
        for (int j = iter[1]; j <= iter[3]; ++j)
        {
            map[iter[0]][j] = true;
            map[iter[2]][j] = true;
        }
        
        
        for (int i = iter[0]; i <= iter[2]; ++i)
        {
            for (int j = iter[1]; j <= iter[3]; ++j)
            {
                map[i][j] = true;
            }
        }
    }
     
    for (auto& iter : rectangle)
    {
        for (int i = iter[0] + 1; i < iter[2]; ++i)
        {
            for (int j = iter[1] + 1; j < iter[3]; ++j)
            {
                map[i][j] = false;
            }
        }
    }
    
    BFS(characterX * 2, characterY * 2);
    
    // PrintMap();
    
    return costMap[itemX * 2][itemY * 2] / 2;
}