#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> Set;

int solution(vector<int> elements) {
    int answer = 0;
    
    for (int i = 1; i <= elements.size(); ++i)
    {
        for (int j = 0; j < elements.size(); ++j)
        {
            int Sum = 0;
            for (int k = 0; k < i; ++k)
            {
                Sum += elements[(j + k) % elements.size()];
            }
            
            Set.insert(Sum);
        }
    }
    
    answer = Set.size();
    return answer;
}