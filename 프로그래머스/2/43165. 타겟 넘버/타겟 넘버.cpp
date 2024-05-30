#include <string>
#include <vector>

using namespace std;

int answer = 0;

void BT(vector<int>& numbers, int result, int target, int pos)
{
    if (pos == numbers.size())
    {
        if (result == target)
        {
            answer++;
        }
        return;
    }
    
    BT(numbers, result + numbers[pos], target, pos+1);
    BT(numbers, result - numbers[pos], target, pos+1);
}

int solution(vector<int> numbers, int target) {
    
    BT(numbers, 0, target, 0);
    
    return answer;
}