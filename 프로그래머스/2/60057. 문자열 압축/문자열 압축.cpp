#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    string test = "ababcdcdababcdcd";
    
    for (int i = 1; i <= s.size()/2; ++i)
    {
        int count = 1;
        string str = "";
        for (int start = 0; start < s.size(); start += i)
        {
            // 범위 안인지 체크
            if (start + (2 * i) > s.size())
            {
                if (count != 1)
                    str += to_string(count);
                str += s.substr(start);
                break;
            }
            
            if (s.substr(start, i) == s.substr(start + i, i))
                count ++;
            else
            {
                if (count != 1)
                    str += to_string(count);
                str += s.substr(start, i);

                count = 1;
            }
        }
        
        if (str.length() < answer)
            answer = str.length();
    }
    
    
    return answer;
}