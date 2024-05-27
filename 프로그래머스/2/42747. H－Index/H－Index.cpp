#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 0 1 7 10 11 12 13

// 0, 13 -> 6

// 0, 5 -> 2

int Left, Right, Mid;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for (int i = citations.back(); i >= 0; --i)
    {
        // cout << i << ':' << citations.end() - lower_bound(citations.begin(), citations.end(), i) << '\n';
        
        if (citations.end() - lower_bound(citations.begin(), citations.end(), i) >= i)
        {
            return i;
        }
    }
    
    return answer;
}