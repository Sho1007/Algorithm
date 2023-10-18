#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<char, int> TermMap;

void SplitStringToDate(string String, int& Year, int& Month, int& Day)
{
    int StartPos = 0;
    //cout << String.find(".", StartPos) << '\n';
    
    int EndPos = String.find(".", StartPos);
    Year = stoi(String.substr(StartPos, EndPos - StartPos));
    StartPos = EndPos + 1;
    EndPos = String.find(".", StartPos);
    Month = stoi(String.substr(StartPos, EndPos - StartPos));
    StartPos = EndPos + 1;
    EndPos = String.find(".", StartPos);
    Day = stoi(String.substr(StartPos, EndPos - StartPos));
}

int TodayYear;
int TodayMonth;
int TodayDay;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // Init TermMap
    for (int i = 0; i < terms.size(); ++i)
    {
        TermMap[terms[i][0]] = stoi(terms[i].substr(terms[i].find(' ')));
    }
    
    // Init today to int
    SplitStringToDate(today, TodayYear, TodayMonth, TodayDay);
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        int Year, Month, Day;
        string Date = privacies[i].substr(0, privacies[i].find(' '));
        SplitStringToDate(Date, Year, Month, Day);
        char Term = privacies[i].back();
        
        Month += TermMap[Term];
        
        if (Day == 1)
        {
            Day = 28;
            Month--;
        }
        else Day--;
        
        while (Month > 12)
        {
            Year++;
            Month -= 12;
        }
        
        if (Year < TodayYear)
        {
            answer.push_back(i + 1);
            continue;
        }
        else if (Year == TodayYear)
        {
            if (Month < TodayMonth)
            {
                answer.push_back(i + 1);
                continue;
            }
            else if (Month == TodayMonth)
            {
                if (Day < TodayDay)
                {
                    answer.push_back(i + 1);
                    continue;
                }
            }
        }
    }
    
    
    return answer;
}