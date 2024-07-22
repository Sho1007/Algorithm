#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>(numbers.size(), -1);    
    
    for (int i = numbers.size()-2; i >= 0; --i)
    {
        if (numbers[i] < numbers[i+1])
        {
            answer[i] = i+1;
        }
        else if (answer[i+1] != -1)
        {
            int current = answer[i+1];
            
            while (current != -1)
            {
                if (numbers[i] < numbers[current])
                {
                    answer[i] = current;
                    break;
                }
                else
                {
                    current = answer[current];
                }
            }
        }
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (answer[i] == -1) continue;
        answer[i] = numbers[answer[i]];
    }
    
    return answer;
}