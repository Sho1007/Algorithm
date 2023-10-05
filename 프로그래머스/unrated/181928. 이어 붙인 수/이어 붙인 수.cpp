#include <string>
#include <vector>

using namespace std;

string EvenNum = "";
string OddNum = "";

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        if (num_list[i] % 2 == 0)
        {
            EvenNum += num_list[i] + '0';
        }
        else
        {
            OddNum += num_list[i] + '0';
        }
    }
    
    answer = stoi(EvenNum) + stoi(OddNum);
    return answer;
}