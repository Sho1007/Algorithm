#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long right = 9'223'372'036'854'775'806;
    long long left = 1;
    long long mid;
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        unsigned long long count = 0;
        
        for (int i = 0; i < times.size(); ++i)
        {
            count += mid / times[i];
        }
        if (count >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    
    return answer;
}