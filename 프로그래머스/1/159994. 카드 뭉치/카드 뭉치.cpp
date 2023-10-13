#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    int Cards1Index = 0;
    int Cards2Index = 0;
    
    for (int i = 0; i < goal.size(); ++i)
    {
        if (Cards1Index < cards1.size() && goal[i] == cards1[Cards1Index])
        {
            Cards1Index++;
        }
        else if (Cards2Index < cards2.size() && goal[i] == cards2[Cards2Index])
        {
            Cards2Index++;
        }
        else
        {
            return "No";
        }
    }
    
    return answer;
}