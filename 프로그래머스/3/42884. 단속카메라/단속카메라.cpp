#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
inline int MAX(int A, int B) { return A > B ? A : B; }
inline int MIN(int A, int B) { return A < B ? A : B; }

using namespace std;

int lastPos;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](vector<int>& A, vector<int>& B)->bool
         {
             if (A[0] == B[0])
             {
                 return A[1] < B[1];
             }
             
             return A[0] < B[0];
         });
    
    for (int i = 0; i < routes.size()-1;)
    {
        if (routes[i][1] >= routes[i+1][0])
        {
            routes[i][0] = routes[i+1][0];
            routes[i][1] = MIN(routes[i][1], routes[i+1][1]);
            routes.erase(routes.begin() + i + 1);
            if (i == routes.size() - 1)
            {
                answer++;
                break;
            }
        }
        else
        {
            answer++;
            i++;
            if (i == routes.size() -1)
            {
                answer++;
                break;
            }
        }
    }
    
    
    return answer;
}