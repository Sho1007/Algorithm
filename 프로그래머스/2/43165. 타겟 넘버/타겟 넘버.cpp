#include <string>
#include <vector>

using namespace std;

int Answer = 0;

void BackTracking(vector<int>& numbers, int target, int Current, int Pos)
{
    if (Pos == numbers.size())
    {
        if (Current == target)
        {
            Answer++;
        }
        
        return;
    }
    
    BackTracking(numbers, target, Current + numbers[Pos], Pos + 1);
    BackTracking(numbers, target, Current - numbers[Pos], Pos + 1);
}

int solution(vector<int> numbers, int target) {
    
    BackTracking(numbers, target, 0, 0);
    
    return Answer;
}