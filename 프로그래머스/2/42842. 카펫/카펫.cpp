#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    if (yellow == 1)
    {
        return {3, 3};
    }
    
    // (노랑 세로 * 2) + ((노랑 가로 + 2) * 2) = 갈색
    
    int sqrtYellow = sqrt(yellow);
    cout << sqrtYellow << '\n';
    
    int i = 1;
    for (; i <= sqrtYellow; ++i)
    {
        // i 가 세로
        if ((yellow / i) * i != yellow) continue;
        
        if ((i * 2) + (((yellow / i) + 2) * 2) == brown)
        {
            break;
        }
    }
    
    answer.push_back((yellow / i) + 2);
    answer.push_back(i + 2);
    
    
    return answer;
} 