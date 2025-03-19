#include<iostream>
#include <vector>
using namespace std;
inline int ABS(int A) { return A > 0 ? A : -A; }
inline int MIN(int A, int B) { return A < B ? A : B; }

// 블록의 가로, 세로 길이
int Width, Height;
// 상점의 개수
int N;
// 상점의 위치가 담긴 벡터
vector<pair<int, int>> PosVector;
// 방향을 시계방향으로 변환하기 위한 맵
int ClockwiseSide[5] = { 0, 0, 2, 3, 1 };
// 동근이의 위치
pair<int, int> StartPos;
// 최단 거리의 합
int Answer = 0;

void ConvertToClockwise(pair<int, int>& Input)
{
    if (Input.first == 2)
    {
        Input.second = Width - Input.second;
    }
    else if (Input.first == 3)
    {
        Input.second = Height - Input.second;
    }

    Input.first = ClockwiseSide[Input.first];
}

int GetSideLength(int SideNum)
{
    return SideNum % 2 == 0 ? Width : Height;
}
int GetOtherSideLength(int SideNum)
{
    return SideNum % 2 == 0 ? Height : Width;
}

int CalcDistance(pair<int, int>& Target)
{
    // 사이드의 거리 (시계방향 바로 다음이면 1, 시계방향 바로 전이면 3)
    int SideDistance = (Target.first - StartPos.first + 4) % 4;
    int ClockwiseDistance = (GetSideLength(StartPos.first) - StartPos.second) + Target.second;
    int CounterClockwiseDistance = StartPos.second + (GetSideLength(Target.first) - Target.second);

    // 같은 사이드, 위치의 차이
    if (SideDistance == 0)
    {
        return ABS(Target.second - StartPos.second);
    }
    // 시계 방향 진행
    else if (SideDistance == 1)
    {
        return ClockwiseDistance;
    }
    // 반시계 방향 진행
    else if (SideDistance == 3)
    {
        return CounterClockwiseDistance;
    }
    // 맞은 편
    else if (SideDistance == 2)
    {
        // 시계 방향 진행과, 반시계 방향 진행 중 작은 것을 반환
        // 인접면의 길이는 시계방향이든, 반시계방향이든 지나가므로 그냥 더함
        return MIN(ClockwiseDistance, CounterClockwiseDistance) + GetOtherSideLength(StartPos.first);
    }

    // 
    return -1;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> Width >> Height;
    cin >> N;
    PosVector = vector<pair<int, int>>(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> PosVector[i].first >> PosVector[i].second;
        ConvertToClockwise(PosVector[i]);
    }

    cin >> StartPos.first >> StartPos.second;
    ConvertToClockwise(StartPos);

    for (int i = 0; i < PosVector.size(); ++i)
    {
        Answer += CalcDistance(PosVector[i]);
    }

    cout << Answer << '\n';

    return 0;
}