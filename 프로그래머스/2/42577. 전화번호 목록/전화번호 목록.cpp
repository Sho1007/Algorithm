#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<string> Set;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Set = unordered_set<string>(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size(); ++i)
    {
        for (int j = 1; j <= phone_book[i].length() - 1; ++j)
        {
            if (Set.find(phone_book[i].substr(0, j)) != Set.end())
            {
                return false;
            }
        }
    }
    
    return answer;
}