#include <iostream>
#include <string>
using namespace std;
inline int MIN(int A, int B) { return A < B ? A : B; }

int N;
string String, NewString;

int Move(char InMoveColor, char InStayColor)
{
    int MoveCount = 0;
    // 안움직일 공 단축
    // 양 사이드의 움직일 색 공의 연속된 수 찾기
    NewString = "";
    for (int i = 0; i < N; ++i)
    {
        if (String[i] == InMoveColor)
        {
            NewString += InMoveColor;
        }
        else
        {
            if (NewString.length() == 0 || NewString.back() != InStayColor)
            {
                NewString += InStayColor;
            }
        }
    }

    int LeftCount = 0;
    int RightCount = 0;

    for (int i = 0; i < NewString.length(); ++i)
    {
        if (NewString[i] == InMoveColor)
        {
            LeftCount++;
        }
        else
        {
            break;
        }
    }
    for (int i = NewString.length() - 1; i >= 0; --i)
    {
        if (NewString[i] == InMoveColor)
        {
            RightCount++;
        }
        else
        {
            break;
        }
    }

    // cout << NewString << '\n';

    if (LeftCount >= RightCount)
    {
        // cout << "Move Left\n";
        for (int i = LeftCount; i < NewString.length(); ++i)
        {
            if (NewString[i] == InMoveColor)
            {
                MoveCount++;
            }
        }
    }
    else
    {
        // cout << "Move Right\n";
        for (int i = NewString.length() - RightCount - 1; i >= 0; --i)
        {
            if (NewString[i] == InMoveColor)
            {
                MoveCount++;
            }
        }
    }

    // cout << "Move " << InMoveColor << " : " << MoveCount << '\n';

    return MoveCount;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> String;

    cout << MIN(Move('R', 'B'), Move('B', 'R')) << '\n';

    return 0;
}