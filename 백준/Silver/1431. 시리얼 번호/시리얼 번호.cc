#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

string Input;
vector<pair<string,int>> Vector;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while (N-->0)
    {
        cin >> Input;
        int Num = 0;

        for (int i = 0; i < Input.length(); ++i)
        {
            if ('0' <= Input[i] && Input[i] <= '9')
            {
                Num += Input[i] - '0';
            }
        }

        Vector.push_back({Input, Num});
    }

    sort(Vector.begin(), Vector.end(), [](pair<string, int>& A, pair<string, int>& B)->bool
    {
        if (A.first.length() == B.first.length())
        {
            if (A.second == B.second)
            {
                return A.first < B.first;
            }

            return A.second < B.second;
        }
        return A.first.length() < B.first.length(); 
    });

    for (int i = 0; i < Vector.size(); ++i)
    {
        cout << Vector[i].first << '\n';
    }
    
    return 0;
}