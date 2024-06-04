#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int parent[101] = {};

int Find(int num)
{
    if (parent[num] == num) return num;
    
    return parent[num] = Find(parent[num]);
}

bool Union(int A, int B)
{
    int parentA = Find(A);
    int parentB = Find(B);
    
    if (parentA == parentB) return false;
    
    parent[parentB] = parentA;
    
    return true;
}


using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int i = 1; i <= 100; ++i)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [](vector<int>& A, vector<int>& B)->bool
         {
             return A[2] < B[2];
         });
    
    for (int i = 0; i < costs.size(); ++i)
    {
        if (Union(costs[i][0], costs[i][1]))
        {
            answer += costs[i][2];
        }
    }
    
    return answer;
}