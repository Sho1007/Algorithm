#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

#define MAX 10000000

using namespace std;

int answer = 0;
vector<bool> isPrime;
unordered_set<int> primeUSet;

void BT(string& numbers, string& current)
{
    if (current.length() > 0)
    {
        int currentNum = stoi(current); 
        if (primeUSet.find(currentNum) == primeUSet.end() && isPrime[currentNum])
        {
            primeUSet.insert(currentNum);
            // cout << currentNum << '\n';
            answer++;
        }
    }
    
    if (numbers.length() == 0)
    {
        return;
    }
    
    for (int i = 0; i < numbers.length(); ++i)
    {
        current.push_back(numbers[i]);
        numbers.erase(numbers.begin() + i);
        BT(numbers, current);
        numbers.insert(numbers.begin() + i, current.back());
        current.pop_back();
    }
}

int solution(string numbers) {
    // 에라토스테네스의 체
    isPrime = vector<bool>(MAX, true);
    
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i < MAX; ++i)
    {
        if (isPrime[i] == false) continue;
        
        if (isPrime[i] == false) continue;
        for (int j = 2; i * j < MAX; ++j)
        {
            isPrime[i * j] = false;
        }
    }
    
    string current = "";
    BT(numbers, current);
    
    
    return answer;
}