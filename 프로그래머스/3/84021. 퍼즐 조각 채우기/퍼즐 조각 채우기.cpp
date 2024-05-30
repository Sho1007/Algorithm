#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 퍼즐을 raw position 을 배열에 저장하고, [회전] 시킨 값들도 전부 배열로 저장
// 그냥 칸마다 비교하면 결국 내가 기준점으로 잡은 칸과 비교할 수 밖에 없음
vector<vector<pair<int,int>>> blockVector[4];
vector<vector<bool>> tableVisited;
vector<bool> usedBlock;
int answer = 0;

int dX[4] = {-1, 1, 0, 0};
int dY[4] = {0, 0, -1, 1};

void SortVector(vector<pair<int,int>>& target)
{
    for (int i = 1; i < target.size(); ++i)
    {
        target[i].first -= target[0].first;
        target[i].second -= target[0].second;
    }
    target[0].first = 0;
    target[0].second = 0;
    sort(target.begin(), target.end());
}

void RotateBlock(vector<pair<int,int>>& currentBlock)
{
    for (int i = 0; i < currentBlock.size(); ++i)
    {
        int temp = -currentBlock[i].first;
        currentBlock[i].first = currentBlock[i].second;
        currentBlock[i].second = temp;
    }
    sort(currentBlock.begin(), currentBlock.end());
}

void FindBlock(vector<vector<int>>& table, pair<int,int> startPos)
{
    vector<pair<int,int>> currentBlock;
    queue<pair<int,int>> blockQueue;
    blockQueue.push(startPos);
    currentBlock.push_back(startPos);
    tableVisited[startPos.first][startPos.second] = true;
    
    while (blockQueue.empty() == false)
    {
        pair<int,int> currentPos = blockQueue.front(); blockQueue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextX = currentPos.first + dX[i];
            int nextY = currentPos.second + dY[i];
            
            if (nextX < 0 || nextX >= table.size() || nextY < 0 || nextY >= table.size()) continue;
            if (tableVisited[nextX][nextY] || table[nextX][nextY] != 1) continue;
            tableVisited[nextX][nextY] = true;
            blockQueue.push({nextX, nextY});
            currentBlock.push_back({nextX, nextY});
        }
    }
    SortVector(currentBlock);
    for (int i = 0; i < 4; ++i)
    {
        blockVector[i].push_back(currentBlock);
        RotateBlock(currentBlock);
        // for (int j = 0; j < blockVector[i].back().size(); ++j)
        // {
        //     cout << '{' << blockVector[i].back()[j].first << ',' << blockVector[i].back()[j].second << "} ";
        // }
        // cout << '\n';
    }
    // cout << '\n';
}

bool IsSameBlock(vector<pair<int,int>>& A, vector<pair<int,int>>& B)
{
    if (A.size() != B.size()) return false;
    
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i].first == B[i].first && A[i].second == B[i].second) continue;
        else return false;
    }
    
    return true;
}

void PutBlock(vector<vector<int>>& game_board, pair<int,int> startPos)
{
    vector<pair<int,int>> currentBlock;
    queue<pair<int,int>> blockQueue;
    blockQueue.push(startPos);
    currentBlock.push_back(startPos);
    tableVisited[startPos.first][startPos.second] = true;
    
    while (blockQueue.empty() == false)
    {
        pair<int,int> currentPos = blockQueue.front(); blockQueue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nextX = currentPos.first + dX[i];
            int nextY = currentPos.second + dY[i];
            
            if (nextX < 0 || nextX >= game_board.size() || nextY < 0 || nextY >= game_board.size()) continue;
            if (tableVisited[nextX][nextY] || game_board[nextX][nextY] != 0) continue;
            tableVisited[nextX][nextY] = true;
            blockQueue.push({nextX, nextY});
            currentBlock.push_back({nextX, nextY});
        }
    }
    
    // sort(currentBlock.begin(), currentBlock.end());
    
    for (int i = 1; i < currentBlock.size(); ++i)
    {
        currentBlock[i].first -= currentBlock[0].first;
        currentBlock[i].second -= currentBlock[0].second;
    }
    
    currentBlock[0] = {0, 0};
    
    sort(currentBlock.begin(), currentBlock.end());
    
    for (int i = 0; i < blockVector[0].size(); ++i)
    {
        if (usedBlock[i]) continue;
        for (int j = 0; j < 4; ++j)
        {
            if (IsSameBlock(currentBlock, blockVector[j][i]))
            {
                usedBlock[i] = true;
                answer += currentBlock.size();
                return;
            }
        }
    }
    
    for (int i = 0; i < currentBlock.size(); ++i)
    {
        tableVisited[currentBlock[i].first + startPos.first][currentBlock[i].second + startPos.second] = false;      
    }
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    tableVisited = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table.size(); ++j)
        {
            if (tableVisited[i][j] == false && table[i][j] == 1)
            {
                FindBlock(table, {i, j});
            }
        }
    }
    
    usedBlock = vector<bool>(blockVector[0].size(), false);
    tableVisited = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    
    for (int i = 0; i < game_board.size(); ++i)
    {
        for (int j = 0; j < game_board[i].size(); ++j)
        {
            if (tableVisited[i][j] == false && game_board[i][j] == 0)
            {
                PutBlock(game_board, {i, j});
            }
        }
    }
    
    
    return answer;
}