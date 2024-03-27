#include <iostream>
#include <queue>
#define MAX 987'654'321
using namespace std;

vector<vector<int>> Board = vector<vector<int>>(51, vector<int>(51, MAX));
queue<int> Queue;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // 양방향
    // 이동 시간
    // 1번에서 시작
    // N개의 마을 중 K 시간 이하 배달 가능 마을에서만 주문 접수
    // 최종 거리 중 K 이하의 마을의 갯수 출력
    
    for (int i = 0; i < road.size(); ++i)
    {
        if (Board[road[i][0]][road[i][1]] > road[i][2])
        {
            Board[road[i][0]][road[i][1]] = road[i][2];
            Board[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        Board[i][i] = 0;
    }
    
    
    // for (int i = 1; i <= N; ++i)
    // {
    //     for (int j = 1; j <= N; ++j)
    //     {
    //         cout << Board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    
    
    for (int i = 2; i <= N; ++i)
    {
        if (Board[1][i] != MAX)
        {
            Queue.push(i);
        }
    }
    
    while (Queue.empty() == false)
    {
        int Current = Queue.front(); Queue.pop();
        // 1 -> Current 로의 비용 + Current -> i 로의 비용이 1 -> i 로의 비용보다 싸다면, 최신화 후 Queue 에 삽입
        // 만약 Current -> i 로의 비용이 MAX 라면 길이 없으므로 continue
        for (int i = 1; i <= N; ++i)
        {
            if (Board[Current][i] == MAX) continue;
            
            if (Board[1][Current] + Board[Current][i] < Board[1][i])
            {
                Board[1][i] = Board[1][Current] + Board[Current][i];
                Board[i][1] = Board[1][Current] + Board[Current][i];
                
                Queue.push(i);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (Board[1][i] <= K) answer++;
        // cout << Board[1][i] << ' ';
    }
    cout << '\n';

    return answer;
}