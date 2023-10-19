#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> FeeMap;

map<string, string> InTimeMap;

void CalcFee(string CarNumber, string InTime, string OutTime)
{
    int InHour = stoi(InTime.substr(0, 2));
    int InMin = stoi(InTime.substr(3, 2));

    int OutHour = stoi(OutTime.substr(0, 2));
    int OutMin = stoi(OutTime.substr(3, 2));
    
    int Result = 0;
    
    int DeltaHour =  OutHour - InHour;
    int DeltaMin = OutMin - InMin;
    
    //cout << CarNumber << " : " << DeltaHour << ' ' << DeltaMin << '\n';
    
    DeltaMin += (DeltaHour * 60);
    
    //cout << CarNumber << " : " << DeltaMin << '\n';
    
    FeeMap[CarNumber] += DeltaMin;
    InTimeMap[CarNumber] = "Paid";
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for (int i = 0; i < records.size(); ++i)
    {
        if (records[i].substr(11) == "IN")
        {
            // IN
            InTimeMap[records[i].substr(6, 4)] = records[i].substr(0, 5);
        }
        else
        {
            // OUT
            string CarNumber = records[i].substr(6, 4);
            string OutTime = records[i].substr(0, 5);
            string InTime = InTimeMap[CarNumber];
            
            CalcFee(CarNumber, InTime, OutTime);
        }
    }
    
    for (auto& Iter : InTimeMap)
    {
        if (Iter.second != "Paid")
        {
            CalcFee(Iter.first, Iter.second, "23:59");
        }
    }
    
    for (auto& Iter : FeeMap)
    {
        int Result = fees[1];
        int Time = Iter.second - fees[0];
        
        if (Time > 0)
        {
            if (Time % fees[2] != 0) Time += fees[2];
            
            Result += (Time / fees[2]) * fees[3];
        }
        answer.push_back(Result);
    }
    
    
    
    return answer;
}