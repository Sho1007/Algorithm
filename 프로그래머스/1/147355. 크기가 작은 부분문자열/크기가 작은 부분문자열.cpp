#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    //int Target = stoi(p);
    for (int i = 0; i < t.size(); ++i)
    {
        string Current = t.substr(i, p.size());
        if (Current.size() == p.size())
        {
            if (Current <= p) answer++;
            //int CurrentInt = stoi(Current);
        }
        //cout << t.substr(i, p.size()) << '\n';
    }
    
    return answer;
}