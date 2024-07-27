#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = -1;
    
    sort(data.begin(), data.end(), [col](vector<int>& A, vector<int>& B)->bool
         {
             if (A[col-1] == B[col-1])
             {
                 return A[0] > B[0];
             }
             
             return A[col-1] < B[col-1];
         });
    
    for (int i = row_begin; i <= row_end; ++i)
    {
        int current = 0;
        for (auto iter : data[i-1])
        {
            current += iter % i;
        }
        
        if (answer == -1) answer = current;
        else answer ^= current;
    }
    
    return answer;
}