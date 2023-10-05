#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int PowSum = 0;
    
    int Mul = 1;
    
    for (int i = 0; i < num_list.size(); ++i)
    {
        PowSum += num_list[i];
        
        Mul *= num_list[i];
    }
    
    //cout << Mul << ' ' << PowSum * PowSum << '\n';
    answer = Mul < PowSum * PowSum;
    
    return answer;
}