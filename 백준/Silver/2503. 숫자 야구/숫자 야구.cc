#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, Answer = 0;

vector<vector<int>> Vector;

vector<int> NumberVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void BackTracking(int Current)
{
    if (Current > 100)
    {
        string A = to_string(Current);
        bool bIsPossible = true;
        for (int j = 0; j < Vector.size(); ++j)
        {
            string B = to_string(Vector[j][0]);
            int Strike = 0, Ball = 0;

            if (A.find(B[0]) != string::npos) Ball++;
            if (A.find(B[1]) != string::npos) Ball++;
            if (A.find(B[2]) != string::npos) Ball++;
            
            for (int k = 0; k < 3; ++k)
            {
                if (A[k] == B[k])
                {
                    Ball--;
                    Strike++;
                }
            }

            if (Strike != Vector[j][1] || Ball != Vector[j][2])
            {
                bIsPossible = false;
                break;
            }
        }

        if (bIsPossible)
        {
            // cout << A << '\n';
            Answer++;
        }

        return;
    }

    for (int i = 0; i < NumberVector.size(); ++i)
    {
        Current *= 10;

        Current += NumberVector[i];

        NumberVector.erase(NumberVector.begin() + i);

        BackTracking(Current);

        NumberVector.insert(NumberVector.begin() + i, Current % 10);

        Current /= 10;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

    cin >> N;

    Vector = vector<vector<int>>(N, vector<int>(3, 0));

    for (int i = 0; i < N; ++i)
    {
        cin >> Vector[i][0] >> Vector[i][1] >> Vector[i][2];
    }

    BackTracking(0);

    cout << Answer << '\n';
    
    return 0;
}