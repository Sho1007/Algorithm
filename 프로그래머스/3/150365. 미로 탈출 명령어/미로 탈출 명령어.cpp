#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

inline int ABS(int A) { return A >= 0 ? A : -A; }

int N, M, R, C, K;
string MinPath = "";

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

// void FindPath(int n, int m, int x, int y, int r, int c, int k)
// {
//     queue<State> Queue;
    
//     Queue.push(State({x, y}, 0, ""));
    
//     while (Queue.empty() == false)
//     {
//         State Current = Queue.front(); Queue.pop();
        
//         if (Current.Cost == k)
//         {
//             if (Current.Pos.first == r && Current.Pos.second == c)
//             {
//                 PathVector.push_back(Current.Path);
//             }
            
//             continue;
//         }
        
//         for (int i = 0; i < 4; ++i)
//         {
//             int NextX = Current.Pos.first + dx[i];
//             int NextY = Current.Pos.second + dy[i];
            
//             if (NextX < 1 || NextX > n || NextY < 1 || NextY > m) continue;
//             if (ABS(NextX - r) + ABS(NextY - c) > k) continue;
            
//             switch(i)
//             {
//                 case 0:
//                     Queue.push(State({NextX, NextY}, Current.Cost + 1, Current.Path + 'u'));
//                     break;
//                 case 1:
//                     Queue.push(State({NextX, NextY}, Current.Cost + 1, Current.Path + 'd'));
//                     break;
//                 case 2:
//                     Queue.push(State({NextX, NextY}, Current.Cost + 1, Current.Path + 'l'));
//                     break;
//                 case 3:
//                     Queue.push(State({NextX, NextY}, Current.Cost + 1, Current.Path + 'r'));
//                     break;
//             }
//         }
//     }
// }

string BackTracking(pair<int,int> Pos, int Cost, string Path)
{
    while (K > 0)
    {
        // cout << Path << '\n';
        for (int i = 0; i < 4; ++i)
        {
            int NextX = Pos.first + dx[i];
            int NextY = Pos.second + dy[i];
            
            // cout << NextX << ',' << NextY << '\n';

            if (NextX < 1 || NextX > N || NextY < 1 || NextY > M) continue;
            if (ABS(NextX - R) + ABS(NextY - C) > K) continue;
            
            Pos.first = NextX;
            Pos.second = NextY;
            
            switch (i)
            {
                case 0:
                    Path += 'd';
                    break;
                case 1:
                    Path += 'l';
                    break;
                case 2:
                    Path += 'r';
                    break;
                case 3:
                    Path += 'u';
                    break;
            }
            break;
        }
        
        K--;
    }
    
    if (Pos.first != R || Pos.second != C) return "impossible";
    
    return Path;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    N = n;
    M = m;
    R = r;
    C = c;
    K = k;
    
    return BackTracking({x, y}, 0, "");
}