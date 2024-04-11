#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> Parent;

int GetParent(int Current)
{
    if (Parent[Current] == Current) return Current;
    
    return Parent[Current] = GetParent(Parent[Current]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    Parent = vector<int>(n+1);
    
    for (int i = 1; i <= n; ++i)
    {
        Parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [](vector<int>& A, vector<int>& B)->bool
         {
             return A[2] < B[2];
         });
    
    for (int i = 0; i < costs.size(); ++i)
    {
        int ParentA = GetParent(costs[i][0]);
        int ParentB = GetParent(costs[i][1]);
        if (ParentA == ParentB) continue;
        
        answer += costs[i][2];
        Parent[ParentA] = ParentB;
        
        
    }
    
    return answer;
}