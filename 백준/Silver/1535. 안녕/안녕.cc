#include <iostream>
using namespace std;

int N;
int Cost[20] = {};
int Joy[20] = {};
int MaxJoyArray[101] = {};
int MaxValue = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Cost[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> Joy[i];

        for (int j = Cost[i] + 1; j <= 100; ++j)
        {
            if (j != 100 && MaxJoyArray[j] == 0)
            {
                continue;
            }

            int RemainHealth = j - Cost[i];
            if (MaxJoyArray[RemainHealth] < MaxJoyArray[j] + Joy[i])
            {
                MaxJoyArray[RemainHealth] = MaxJoyArray[j] + Joy[i];

                if (MaxValue < MaxJoyArray[RemainHealth])
                {
                    MaxValue = MaxJoyArray[RemainHealth];
                }
            }
        }

        /*cout << Cost[i] << " : " << Joy[i] << '\n';
        for (int j = 100; j > 0; --j)
        {
            cout << j << " : " << MaxJoyArray[j] << '\n';
        }

        cout << '\n';*/
    }
    
    cout << MaxValue << '\n';

    return 0;
}