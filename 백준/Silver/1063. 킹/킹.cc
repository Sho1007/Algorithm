#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

pair<int, int> KingPos, StonePos;
int N;
map<string, int> DirY = { {"R", 0}, {"L", 0}, {"B", -1}, {"T", 1}, {"RT", 1}, {"LT", 1}, {"RB", -1}, {"LB", -1} };
map<string, int> DirX = { {"R", 1}, {"L", -1}, {"B", 0}, {"T", 0}, {"RT", 1}, {"LT", -1}, {"RB", 1}, {"LB", -1} };
string Input;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> Input;

    KingPos.second = (Input[0] - 'A') + 1;
    KingPos.first = Input[1] - '0';

    cin >> Input;

    StonePos.second = (Input[0] - 'A') + 1;
    StonePos.first = Input[1] - '0';

    cin >> N;

    while (N-- > 0)
    {
        cin >> Input;

        int NextKingPosY = KingPos.first + DirY[Input];
        int NextKingPosX = KingPos.second + DirX[Input];

        // 왕의 다음 목적지가 판 밖이면 무시
        if (NextKingPosY < 1 || NextKingPosY > 8 || NextKingPosX < 1 || NextKingPosX > 8) continue;

        // 왕의 다음 목적지가 돌의 위치인지 확인
        if (NextKingPosY == StonePos.first && NextKingPosX == StonePos.second)
        {
            int NextStonePosY = StonePos.first + DirY[Input];
            int NextStonePosX = StonePos.second + DirX[Input];

            // 돌의 다음 목적지가 판 밖이면 무시
            if (NextStonePosY < 1 || NextStonePosY > 8 || NextStonePosX < 1 || NextStonePosX > 8) continue;

            StonePos.first = NextStonePosY;
            StonePos.second = NextStonePosX;
        }

        KingPos.first = NextKingPosY;
        KingPos.second = NextKingPosX;
    }

    cout << (char)((KingPos.second - 1) + 'A') << (char)(KingPos.first + '0') << '\n';
    cout << (char)((StonePos.second - 1) + 'A') << (char)(StonePos.first+ '0') << '\n';

    return 0;
}