#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 예약을 운영할 수 있는 최소 방의 갯수
// 방 준비 시간은 10분
// 넣을 때 10분 더해서 넣고
// 체크할 때 그것보다 입실 시간이 늦으면 갱신
// 만약 다 찼다면 push back

struct Comp
{
    bool operator()(pair<int,int>& A, pair<int,int>& B)
    {
        if (A.first == B.first)
        {
            return A.second > B.second;
        }
        return A.first > B.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> PQ;

int solution(vector<vector<string>> book_time) {
    
    sort(book_time.begin(), book_time.end(), [](auto& A, auto& B)->bool
         {
             
             int StartHourA = stoi(A[0].substr(0, 2));
             int StartMinA = stoi(A[0].substr(3, 2));
             int StartHourB = stoi(B[0].substr(0, 2));
             int StartMinB = stoi(B[0].substr(3, 2));
             
             if (StartHourA == StartHourB) return StartMinA < StartMinB;
            
             return StartHourA < StartHourB;
         });
    
    for (int i = 0; i < book_time.size(); ++i)
    {
        int StartHour = stoi(book_time[i][0].substr(0, 2));
        int StartMin = stoi(book_time[i][0].substr(3, 2));
        
        if (PQ.size() > 0)
        {
            pair<int,int> Fast = PQ.top();
            
            if (Fast.first < StartHour || (Fast.first == StartHour && Fast.second <= StartMin))
            {
                PQ.pop();
            }
        }
        
        int EndHour = stoi(book_time[i][1].substr(0, 2));
        int EndMin = stoi(book_time[i][1].substr(3, 2));
        
        EndMin += 10;
        
        if (EndMin >= 60)
        {
            EndMin -= 60;
            EndHour++;
        }
        
        PQ.push({EndHour, EndMin});
        
        //cout << PQ.size() << '\n';
    }
 
    return PQ.size();
}