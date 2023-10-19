#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<string,int>> WantVector;
map<string, int> SaleMap;

bool Check()
{
    bool bIsPossible = true;
    for (int i = 0; i < WantVector.size(); ++i)
    {
        if (SaleMap[WantVector[i].first] >= WantVector[i].second) continue;
        else
        {
            bIsPossible = false;
            break;
        }
    }
    
    return bIsPossible;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i = 0; i < want.size(); ++i)
    {
        WantVector.push_back({want[i], number[i]});
    }
    
    for (int i = 0; i < discount.size(); ++i)
    {
        if (i >= 10)
        {
            SaleMap[discount[i - 10]]--;   
        }
        SaleMap[discount[i]]++;
        if (Check()) answer++;
    }
    
    
    return answer;
}