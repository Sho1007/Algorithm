#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> Triangle = vector<vector<int>>(1000, vector<int>(1000, -1));
int Current = 1;
int Mode = 0;
int Count = 0;
int X = 0, Y = 0;

vector<int> solution(int n) {
    vector<int> answer;
    
    int TempN = n;
    
    while (n > 0)
    {
        Triangle[Y][X] = Current++;
        Count++;
        if (Count == n)
        {
            n--;
            Count = 0;
            Mode = (Mode + 1) % 3;
        }
        
        switch(Mode)
        {
            case 0:
                Y++;
                break;
            case 1:
                X++;
                break;
            case 2:
                Y--;
                X--;
                break;
        }
    }
    
    for (int i = 0; i < TempN; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            answer.push_back(Triangle[i][j]);
        }
    }
    
    
    return answer; 
}