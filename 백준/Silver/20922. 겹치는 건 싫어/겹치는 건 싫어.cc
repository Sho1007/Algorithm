#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N, K, StartPos = 0, CurrentLength = 0, MaxLength = 0;
map<int, queue<int>> PosQueueMap;
vector<int> Array;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    Array = vector<int>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Array[i];
        PosQueueMap[Array[i]].push(i);
        if (PosQueueMap[Array[i]].size() > K)
        {
            // 길이 절삭
            int RemovePos = PosQueueMap[Array[i]].front();
            PosQueueMap[Array[i]].pop();

            // 시작 지점부터 RemovePos까지의 등장 숫자들을 제거
            for (int j = StartPos; j < RemovePos; ++j)
            {
                PosQueueMap[Array[j]].pop();
            }
            CurrentLength = i - RemovePos;
            StartPos = RemovePos + 1;
        }
        else
        {
            CurrentLength++;
        }

        if (MaxLength < CurrentLength)
        {
            MaxLength = CurrentLength;
        }
    }

    cout << MaxLength << '\n';

    return 0;
}