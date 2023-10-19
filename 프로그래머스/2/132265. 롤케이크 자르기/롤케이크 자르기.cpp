#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> Left;
map<int, int> Right;

int LeftCount = 0;
int RightCount = 0;

int solution(vector<int> topping) {
    int answer = 0;
    
    for (int i = 0; i < topping.size(); ++i)
    {
        if (++Right[topping[i]] == 1) RightCount++;
    }
    
    for (int i = 0; i < topping.size(); ++i)
    {
        if (--Right[topping[i]] == 0) RightCount--;
        if (Left[topping[i]]++ == 0) LeftCount++;
        
        if (LeftCount == RightCount) answer++;
    }
    
    return answer;
}