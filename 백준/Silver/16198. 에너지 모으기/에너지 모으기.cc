#include <iostream>
#include <vector>
using namespace std;

int N, Answer = 0;

vector<int> Beads;

void GetEnergy(int Energy)
{
    if (Beads.size() == 2)
    {
        if (Energy > Answer)
        {
            Answer = Energy;
        }

        return;
    }

    for (int i = 1; i < Beads.size() - 1; ++i)
    {
        int Current = Beads[i];
        Beads.erase(Beads.begin() + i);
        GetEnergy(Energy + (Beads[i - 1] * Beads[i]));
        Beads.insert(Beads.begin() + i, Current);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    Beads = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Beads[i];
    }

    GetEnergy(0);

    cout << Answer << '\n';

    return 0;
}