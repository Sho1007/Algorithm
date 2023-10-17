#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> V = { "aya", "ye", "woo", "ma" };

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); ++i)
    {
        cout << babbling[i] << " : ";
        string Before = "";
        while (true)
        {
            bool bIsErased = false;
            for (int j = 0; j < V.size();)
            {
                if (V[j] == babbling[i].substr(0, V[j].size()))
                {
                    if (V[j] == Before) break;
                    Before = V[j];
                    babbling[i] = babbling[i].substr(V[j].size());
                    bIsErased = true;
                    break;
                    //cout << babbling[i] << '\n';
                }
                else j++;
            }
            if (bIsErased == false) break;
        }
        if (babbling[i].size() == 0) answer++;
    }
    
    return answer;
}