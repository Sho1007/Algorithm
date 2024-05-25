#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

multiset<int> s;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (uint i = 0; i < operations.size(); ++i)
    {
        int num = stoi(operations[i].substr(2, operations[i].size() - 2));
        switch(operations[i][0])
        {
            case 'I' :
                s.insert(num);
                break;
            case 'D' :
                if (s.size() == 1)
                {
                    s.clear();
                    break;
                }
                if (num == 1)
                {
                    // 최대값 삭제
                    if (s.size() != 0)
                    {
                        auto iter = s.end();
                        iter--;
                        s.erase(iter);
                    }
                }
                else
                {
                    // 최소값 삭제
                    if (s.size() != 0)
                    {
                        s.erase(s.begin());
                    }
                }
                break;
        }
    }
    if (s.size() == 0) return {0, 0};
    if (s.size() == 1) return {*s.begin(), *s.begin()};
    
    auto iter = s.end();
    iter--;
    return {*iter, *s.begin()};
}