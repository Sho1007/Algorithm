#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.size(); ++i)
    {
        bool bIsFinded = false;
        for (int j = i - 1; j >= 0; --j)
        {
            if (s[i] == s[j])
            {
                bIsFinded = true;
                answer.push_back(i - j);
                break;
            }
        }
        
        if (!bIsFinded) answer.push_back(-1);
    }
    
    return answer;
}