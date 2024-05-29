#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int ABS(int A) { return A > 0 ? A : -A; }
inline int MIN(int A, int B) { return A < B ? A : B; }

int matrix[101][101] = {};
int N;

vector<bool> visited;

int DFS(int startPos)
{
    int result = 1;
    
    for (int i = 1; i <= N; ++i)
    {
        if (matrix[startPos][i] == 1 && visited[i] == false)
        {
            visited[i] = true;
            result += DFS(i);
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    N = n;
    
    for (int i = 0; i < wires.size(); ++i)
    {
        matrix[wires[i][0]][wires[i][1]] = 1;
        matrix[wires[i][1]][wires[i][0]] = 1;
    }
    
    
    
    for (int i = 0; i < wires.size(); ++i)
    {
        visited = vector<bool>(n+1, false);
        
        matrix[wires[i][0]][wires[i][1]] = 0;
        matrix[wires[i][1]][wires[i][0]] = 0;
        
        visited[wires[i][0]] = true;
        visited[wires[i][1]] = true;
        
        int firstCount = DFS(wires[i][0]);
        int secondCount = DFS(wires[i][1]);
        
        // cout << i << " : " << firstCount << ',' << secondCount << '\n';
        
        answer = MIN(answer, ABS(firstCount - secondCount));
        
        matrix[wires[i][0]][wires[i][1]] = 1;
        matrix[wires[i][1]][wires[i][0]] = 1;
    }
    
    
    return answer;
}