#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int Number, Gold, Silver, Bronze;

vector<vector<int>> Vector;

int main()
{
    cin >> N >> K;

    while (N-->0)
    {
        vector<int> CurrentVector = vector<int>(4);
        cin >> CurrentVector[0] >> CurrentVector[1] >> CurrentVector[2] >> CurrentVector[3];
        Vector.push_back(CurrentVector);
    }

    sort(Vector.begin(), Vector.end(), [](vector<int>& A, vector<int>& B)->bool
    {
        if (A[1] == B[1])
        {
            if (A[2] == B[2])
            {
                return A[3] > B[3];
            }

            return A[2] > B[2];
        }

        return A[1] > B[1];
    });

    if (Vector[0][0] == K)
    {
        cout << 1 << '\n';
    }
    else
    {
        int Rank = 1;

        for (int i = 1; i < Vector.size(); ++i)
        {
            if (Vector[i][1] != Vector[i-1][1] ||
                Vector[i][2] != Vector[i-1][2] ||
                Vector[i][3] != Vector[i-1][3])
            {
                Rank++;
            }

            if (Vector[i][0] == K)
            {
                cout << Rank << '\n';
                break;
            }
                
        }
    }

    return 0;
}