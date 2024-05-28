#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

queue<string> stringQueue;
vector<string> stringVector;

char charArray[5] = {'A', 'E', 'I', 'O', 'U'};

int solution(string word) {
    int answer = 0;
    
    stringQueue.push("");
    
    while (stringQueue.empty() == false)
    {
        string current = stringQueue.front(); stringQueue.pop();
        if (current.length() == 5) continue;
        
        for (int i = 0; i < 5; ++i)
        {
            string newString = current + charArray[i];
            stringQueue.push(newString);
            stringVector.push_back(newString);
        }
    }
    
    sort(stringVector.begin(), stringVector.end());
    
    answer = lower_bound(stringVector.begin(), stringVector.end(), word) - stringVector.begin() + 1;
    
    return answer;
}