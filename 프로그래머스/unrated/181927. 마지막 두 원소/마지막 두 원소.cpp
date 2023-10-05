#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    
    int Back = num_list.back();
    int Before = num_list[num_list.size() - 2];
    
    if (Before < Back) num_list.push_back(Back - Before);
    else num_list.push_back(Back * 2);
    
    return num_list;
}