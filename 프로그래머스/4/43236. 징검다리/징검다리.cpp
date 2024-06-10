#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool CheckDistance(int distance, vector<int>& rocks, int n, int mid)
{
    if (mid > distance) return  false;
    
    cout << mid << '\n';
    
    int prev = 0;
    int removeCount = 0;
    
    for (int i = 0; i < rocks.size(); ++i)
    {
        if (rocks[i] - prev < mid || distance - rocks[i] < mid)
        {
            if (++removeCount > n) return false;
        }
        else
        {
            prev = rocks[i];
        }
    }
    
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    if (rocks.size() == n) return distance;
    int answer = 0;
    
    int right = distance;
    int left = 1;
    int mid;
    
    sort(rocks.begin(), rocks.end());
    
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        if (CheckDistance(distance, rocks, n, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer;
}