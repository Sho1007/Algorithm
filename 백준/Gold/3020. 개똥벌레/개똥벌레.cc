#include <iostream>
#include <vector>
using namespace std;

int N, H, Input;

vector<int> Bottom, Top;
bool isBottom = true;

int CurrentObstacle;
int MinObstacle = 987'654'321, MinCount = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> H;

    Bottom = vector<int>(H + 1, 0);
    Top = vector<int>(H + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        if (isBottom)
        {
            Bottom[Input]++;
        }
        else
        {
            Top[Input]++;
        }

        isBottom = !isBottom;
    }

    for (int i = H - 1; i > 0; --i)
    {
        Bottom[i] += Bottom[i + 1];
    }

    for (int i = H - 1; i > 0; --i)
    {
        Top[i] += Top[i + 1];
    }

    for (int CurrentHeight = 1; CurrentHeight <= H; ++CurrentHeight)
    {
        CurrentObstacle = Bottom[CurrentHeight] + Top[H - CurrentHeight + 1];
        if (CurrentObstacle < MinObstacle)
        {
            MinObstacle = CurrentObstacle;
            MinCount = 1;
        }
        else if (CurrentObstacle == MinObstacle)
        {
            MinCount++;
        }
    }

    cout << MinObstacle << ' ' << MinCount << '\n';

    return 0;
}