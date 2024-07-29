#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    unsigned long long sum1 = 0, sum2 = 0;
    
    int count = 0;
    int maxCount = queue1.size() * 2 + 2;
    
    for (int iter : queue1)
    {
        sum1 += iter;
    }
    
    for (int iter : queue2)
    {
        sum2 += iter;
    }
    
    int index1 = 0, index2 = 0;
    
    while (count <= maxCount)
    {
        // cout << sum1 << ' ' << sum2 << '\n';
        if (sum1 == sum2) return count;
        
        count++;
        if (sum1 < sum2)
        {
            sum1 += queue2[index2];
            sum2 -= queue2[index2];
            queue1.emplace_back(queue2[index2++]);
        }
        else if (sum1 > sum2)
        {
            sum2 += queue1[index1];
            sum1 -= queue1[index1];
            queue2.emplace_back(queue1[index1++]);
        }
    }
    
    return answer;
}