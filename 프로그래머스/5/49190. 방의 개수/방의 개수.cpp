#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int dX[8] = {-1,    -1,     0,      1,      1,      1,      0,      -1};
int dY[8] = {0,     1,      1,      1,      0,      -1,     -1,     -1};

unordered_set<string> isVisitedArrow;
unordered_set<string> isVisitedPos;
vector<int> newArrows;

int solution(vector<int> arrows) {
    int answer = 0;
    
    newArrows = vector<int>(arrows.size() * 2);
    
    for (int i = 0; i < arrows.size(); ++i)
    {
        newArrows[i*2] = arrows[i];
        newArrows[i*2+1] = arrows[i];
    }
    
    int x = 0, y = 0;
    
    int nextX, nextY;
    
    string pos = "0,0", nextPos, arrow;
    
    isVisitedPos.insert(pos);
    
    for (int i = 0; i < newArrows.size(); ++i)
    {
        nextX = x + dX[newArrows[i]];
        nextY = y + dY[newArrows[i]];
        
        nextPos = to_string(nextX) + ',' + to_string(nextY);
        
        // cout << i << " : " << arrows[i] << " = " << pos << " -> " << nextPos << '\n';
        
        if (x < nextX || (x == nextX && y < nextY))
        {
            arrow = pos + ':' + nextPos;
        }
        else
        {
            arrow = nextPos + ':' + pos;
        }
        
        if (isVisitedPos.find(nextPos) != isVisitedPos.end())
        {
            if (isVisitedArrow.find(arrow) == isVisitedPos.end())
            {
                // cout << arrow << '\n';
                answer++;
                isVisitedArrow.insert(arrow);
            }
        }
        else
        {
            isVisitedArrow.insert(arrow);
            isVisitedPos.insert(nextPos);
        }
        
        pos = nextPos;
        x = nextX;
        y = nextY;
    }
    
    return answer;
}