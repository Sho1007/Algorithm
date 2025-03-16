#include <iostream>
#include <queue>
#include <vector>
#define INF 987'654'321
using namespace std;

int N;
int StartY, StartX;
int DestY, DestX;
int dY[6] = {-2, -2, 0, 0, 2, 2};
int dX[6] = {-1, 1, -2, 2, -1, 1};
vector<vector<int>> CostBoard;
queue<pair<int,int>> Queue;

void BFS()
{
    Queue.push({StartY, StartX});
    CostBoard[StartY][StartX] = 0;
    while (Queue.empty() == false)
    {
        pair<int,int> Current = Queue.front(); Queue.pop();
        
        for (int i = 0; i < 6; ++i)
        {
            int NextY = Current.first + dY[i];
            int NextX = Current.second + dX[i];
            
            if (NextY < 0 || NextY >= N || NextX < 0 || NextX >= N) continue;
            if (CostBoard[NextY][NextX] <= CostBoard[Current.first][Current.second] + 1) continue;
            
            CostBoard[NextY][NextX] = CostBoard[Current.first][Current.second] + 1;
            Queue.push({NextY, NextX});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> StartY >> StartX >> DestY >> DestX;
    
    CostBoard = vector<vector<int>>(N, vector<int>(N, INF));
    
    BFS();
    
    cout << (CostBoard[DestY][DestX] == INF ? -1 : CostBoard[DestY][DestX]) << '\n';
    
    return 0;
}