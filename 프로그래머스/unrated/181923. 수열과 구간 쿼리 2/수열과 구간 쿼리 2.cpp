#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 0; i < queries.size(); ++i)
    {
        int Result = -1;
        for (int j = queries[i][0]; j <= queries[i][1]; ++j)
        {
            if (arr[j] > queries[i][2])
            {
                if (Result == -1) Result = arr[j];
                else if (Result > arr[j]) Result = arr[j];
            }
        }
        
        answer.push_back(Result);
    }
    
    return answer;
}