#include <iostream>
#include <vector>
using namespace std;

inline int ABS(int A) { return A > 0 ? A : A * -1; }

int N, S, B;
int Dif = 1'000'000'001;

vector<pair<int, int>> IngredVector;
vector<pair<int, int>> ResultVector;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while (N-- > 0)
    {
        cin >> S >> B;
        IngredVector.push_back({ S, B });
    }

    ResultVector.push_back({ 1, 0 });


    for (int i = 0; i < IngredVector.size(); ++i)
    {
        int Size = ResultVector.size();
        for (int j = 0; j < Size; ++j)
        {
            pair<int, int> Result = { IngredVector[i].first * ResultVector[j].first, IngredVector[i].second + ResultVector[j].second };
            int Delta = ABS(Result.first - Result.second);
            if (Delta < Dif)
            {
                Dif = Delta;
            }
            ResultVector.emplace_back(Result);
        }
    }

    cout << Dif << '\n';

    return 0;
}