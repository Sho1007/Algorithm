#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

vector<vector<bool>> TableVisit;
vector<vector<bool>> BoardVisit;
vector<vector<pair<int,int>>> BlockVector[4];
vector<bool> Used;

void PrintBlock()
{
    for (int i = 0; i < BlockVector[0].size(); ++i)
    {
        cout << i << '\n';
        for (int k = 0; k < 4; ++k)
        {
            for (int j = 0; j < BlockVector[0][i].size(); ++j)
            {
                cout << '{' << BlockVector[k][i][j].first << ',' << BlockVector[k][i][j].second << "}, ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

vector<pair<int,int>> MakeBlock(vector<vector<int>>& table, int StartY, int StartX)
{
    vector<pair<int,int>> NewBlock;
    queue<pair<int,int>> Queue;
    
    TableVisit[StartY][StartX] = true;
    Queue.push({StartY, StartX});
    NewBlock.push_back({0, 0});
    
    while (Queue.empty() == false)
    {
        pair<int,int> Current = Queue.front(); Queue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = Current.first + dy[i];
            int NextX = Current.second + dx[i];
            
            if (NextY < 0 || NextY >= table.size() || NextX < 0 || NextX >= table[0].size()) continue;
            if (TableVisit[NextY][NextX] == true || table[NextY][NextX] == 0) continue;
            
            TableVisit[NextY][NextX] = true;
            Queue.push({NextY, NextX});
            NewBlock.push_back({NextY - StartY, NextX - StartX});
        }
    }
    
    return NewBlock;
}

void CheckBlock(vector<vector<int>>& game_board, int StartY, int StartX)
{
    queue<pair<int,int>> Queue;
    vector<pair<int,int>> Blank;
    Queue.push({StartY, StartX});
    Blank.push_back({0, 0});
    BoardVisit[StartY][StartX] = true;
    
    while (Queue.empty() == false)
    {
        pair<int,int> Current = Queue.front(); Queue.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = Current.first + dy[i];
            int NextX = Current.second + dx[i];
            
            if (NextY < 0 || NextY >= game_board.size() || NextX < 0 || NextX >= game_board[0].size()) continue;
            if (BoardVisit[NextY][NextX] == true || game_board[NextY][NextX] == 1) continue;
            
            BoardVisit[NextY][NextX] = true;
            Queue.push({NextY, NextX});
            Blank.push_back({NextY - StartY, NextX - StartX});
        }
    }
    
    sort(Blank.begin(), Blank.end());
    
    // cout << "Blank : ";
    // for (int i = 0; i < Blank.size(); ++i)
    // {
    //     cout << '{'<< Blank[i].first << ',' << Blank[i].second << "}, ";
    // }
    // cout << '\n';
    
    for (int i = 0; i < BlockVector[0].size(); ++i)
    {
        if (Used[i]) continue;
        
        if (Blank.size() != BlockVector[0][i].size()) continue;
        
        for (int j = 0; j < 4; ++j)
        {
            bool bIsSame = true;
            for (int k = 0; k < BlockVector[j][i].size(); ++k)
            {
                if (BlockVector[j][i][k] != Blank[k])
                {
                    bIsSame = false;
                    break;
                }
            }
            if (bIsSame)
            {
                Used[i] = true;
                answer += Blank.size();
                return;
            }
        }
    }
    
    for (int i = 0; i < Blank.size(); ++i)
    {
        BoardVisit[Blank[i].first + StartY][Blank[i].second + StartX] = false;
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    TableVisit = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    
    for (int i = 0; i < table.size(); ++i)
    {
        for (int j = 0; j < table[0].size(); ++j)
        {
            if (TableVisit[i][j] == false && table[i][j] == 1)
            {
                vector<pair<int,int>> NewBlock = MakeBlock(table, i, j);
                BlockVector[0].push_back(NewBlock);
                BlockVector[2].push_back(NewBlock);
                
                for (int k = 0; k < NewBlock.size(); ++k)
                {
                    int Temp = NewBlock[k].first;
                    NewBlock[k].first = NewBlock[k].second;
                    NewBlock[k].second = -Temp;
                }
                
                BlockVector[1].push_back(NewBlock);
                BlockVector[3].push_back(NewBlock);
                
                for (int k = 0; k < NewBlock.size(); ++k)
                {
                    BlockVector[2][BlockVector[2].size()-1][k].first *= -1;
                    BlockVector[2][BlockVector[2].size()-1][k].second *= -1;
                    BlockVector[3][BlockVector[3].size()-1][k].first *= -1;
                    BlockVector[3][BlockVector[3].size()-1][k].second *= -1;
                }
                
                int LastIndex = BlockVector[0].size() - 1;
                sort(BlockVector[0][LastIndex].begin(), BlockVector[0][LastIndex].end());
                sort(BlockVector[1][LastIndex].begin(), BlockVector[1][LastIndex].end());
                sort(BlockVector[2][LastIndex].begin(), BlockVector[2][LastIndex].end());
                sort(BlockVector[3][LastIndex].begin(), BlockVector[3][LastIndex].end());
                
            }
        }
    }
    
    Used = vector<bool>(BlockVector[0].size(), false);
    
    // PrintBlock();
    
    BoardVisit = vector<vector<bool>>(table.size(), vector<bool>(table[0].size(), false));
    
    for (int i = 0; i < game_board.size(); ++i)
    {
        for (int j = 0; j < game_board[0].size(); ++j)
        {
            if (BoardVisit[i][j] == false && game_board[i][j] == 0)
            {
                CheckBlock(game_board, i, j);
            }
        }
    }
    
    return answer;
}