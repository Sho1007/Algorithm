#include <string>
#include <vector>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for (int i = 0; i < section.size();)
    {
        answer++;
        int End = section[i] + m - 1;
        int EndPos = i;
        
        for (int j = i; j < section.size(); ++j)
        {
            if (section[j] <= End) EndPos = j;
            else break;
        }
        
        i = EndPos + 1;
    }
    return answer;
}