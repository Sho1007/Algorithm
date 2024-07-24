#include <string>
#include <vector>

using namespace std;

string numberString[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < 10; ++i)
    {
        while (s.find(numberString[i]) != -1)
        {
            s.replace(s.find(numberString[i]), numberString[i].length(), to_string(i));
        }
    }
    
    return stoi(s);
}