#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Sum = 0;

vector<int> solution(vector<int> sequence, int k) {
    vector<pair<int,int>> PosArray;
    vector<int> answer;
    int Start = 0;
    
    for (int End = 0; End < sequence.size(); ++End)
    {
        Sum += sequence[End];
        
        while (Sum > k)
        {
            Sum -= sequence[Start++];
        }
        
        if (Sum == k)
        {
            PosArray.push_back({Start, End});
        }
    }
    int MinLength = 987654321;
    int MinStart, MinEnd;
    for (auto& Iter : PosArray)
    {
        if (MinLength > Iter.second - Iter.first)
        {
            MinLength = Iter.second - Iter.first;
            MinStart = Iter.first;
            MinEnd = Iter.second;
        }
    }
    
    answer.push_back(MinStart);
    answer.push_back(MinEnd);
    
    
    return answer;
}