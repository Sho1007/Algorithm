#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetDistance(int X1, int Y1, int X2, int Y2)
{
    int DeltaX = X1 - X2;
    int DeltaY = Y1 - Y2;
    
    return (DeltaX*DeltaX) + (DeltaY*DeltaY);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (int i = 0; i < balls.size(); ++i)
    {
        int X = balls[i][0];
        int Y = balls[i][1];
        
        int RemainX = m - X;
        int RemainY = n - Y;
        
        int MinDist = 1'000'000;
        int CurrentDist;
        // Case 1
        if (!(Y == startY && X < startX))
        {
            CurrentDist = GetDistance(startX, startY, -X, Y);
            if (MinDist > CurrentDist) MinDist = CurrentDist;
            
            //cout << -X << ", " << Y << " = " << CurrentDist <<'\n';
        }
        // Case 2
        if (!(X == startX && Y < startY))
        {
            CurrentDist = GetDistance(startX, startY, X, -Y);
            if (MinDist > CurrentDist) MinDist = CurrentDist;
            //cout << X << ", " << -Y << " = " << CurrentDist <<'\n';
        }
        
        // Case 3
        if (!(Y == startY && startX < X))
        {
            CurrentDist = GetDistance(startX, startY, X + (2 * RemainX), Y);
            if (MinDist > CurrentDist) MinDist = CurrentDist;
            //cout << X + (2 * RemainX) << ", " << Y << " = " << CurrentDist <<'\n';
        }
        
        // Case 4
        if (!(X == startX && startY < Y))
        {
            CurrentDist = GetDistance(startX, startY, X, Y + (2 * RemainY));
            if (MinDist > CurrentDist) MinDist = CurrentDist;
            //cout << X << ", " << Y + (2 * RemainY) << " = " << CurrentDist <<'\n';
        }
        answer.push_back(MinDist);
    }
    
    return answer;
}