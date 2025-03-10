#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Input, MaxFrameCount, CurrentFrameCount = 0;
int RecCount[101] = {};
int InTime[101] = {};
vector<int> Frames;

void Print()
{
    for (int i = 0; i < Frames.size(); ++i)
    {
        cout << Frames[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> MaxFrameCount >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        bool IsIn = false;
        int MinRecCount = 987'654'321;
        int MinIndex = 0;
        for (int j = 0; j < Frames.size(); ++j)
        {
            if (Frames[j] == Input)
            {
                IsIn = true;
            }
            if (RecCount[Frames[j]] < MinRecCount)
            {
                MinIndex = j;
                MinRecCount = RecCount[Frames[j]];
            }
        }
        if (IsIn)
        {
            RecCount[Input]++;
        }
        else
        {
            if (Frames.size() >= MaxFrameCount)
            {
                Frames.erase(Frames.begin() + MinIndex);
            }
            RecCount[Input] = 1;
            InTime[Input] = i;
            Frames.push_back(Input);
        }
    }

    sort(Frames.begin(), Frames.end());

    Print();

    return 0;
}