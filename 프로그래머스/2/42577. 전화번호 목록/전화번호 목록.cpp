#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    int answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size()-1; ++i)
    {
        int length = phone_book[i].length() <= phone_book[i+1].length() ? phone_book[i].length() : phone_book[i+1].length();
        
        bool bIsSame = true;
        for (int k = 0; k < length; ++k)
        {
            if (phone_book[i][k] != phone_book[i+1][k])
            {
                bIsSame = false;
                break;
            }
        }
        
        if (bIsSame) return false;
    }
    
    return true;
}