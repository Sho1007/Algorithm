#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> PressCount;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    PressCount = vector<int>(26);
    
    for (int i = 0; i < keymap.size(); ++i)
    {
        for (int j = 0; j < keymap[i].size(); ++j)
        {
            if (PressCount[keymap[i][j] - 'A'] == 0 || PressCount[keymap[i][j] - 'A'] > j + 1) PressCount[keymap[i][j] - 'A'] = j + 1;
        }
    }
    
    for (int i = 0; i < targets.size(); ++i)
    {
        int CurrentCount = 0;
        for (int j = 0; j < targets[i].size(); ++j)
        {
            if (PressCount[targets[i][j] - 'A'] == 0)
            {
                CurrentCount = -1;
                break;
            }
            else
            {
                CurrentCount += PressCount[targets[i][j] - 'A'];
            }
        }
        
        answer.push_back(CurrentCount);
    }
    
    return answer;
}