#include <string>
#include <vector>

using namespace std;

pair<int,int> Start, End;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    Start = {50, 50};
    End = {-1, -1};
    
    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for (int j = 0; j< wallpaper[i].size(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i < Start.first) Start.first = i;
                if (i > End.first) End.first = i;
                if (j < Start.second) Start.second = j;
                if (j > End.second) End.second = j;
            }
        }
    }
    
    answer.push_back(Start.first);
    answer.push_back(Start.second);
    answer.push_back(End.first + 1);
    answer.push_back(End.second + 1);
    
    return answer;
}