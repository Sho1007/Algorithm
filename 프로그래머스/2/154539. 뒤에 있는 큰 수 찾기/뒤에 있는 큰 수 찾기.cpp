#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    for (int i = numbers.size() -1; i >= 0; --i)
    {
        int Pos = i + 1;
        while (Pos != -1)
        {
            if (Pos == numbers.size()) Pos = -1;
            else
            {
                if (numbers[i] < numbers[Pos]) break;
                else Pos = answer[Pos];
            }
        }
        answer[i] = Pos;
    }
    
    for (int i = 0; i < answer.size(); ++i)
    {
        if (answer[i] == -1) continue;
        
        answer[i] = numbers[answer[i]];
    }
    
    return answer;
}