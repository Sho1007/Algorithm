#include <iostream>
#include <unordered_set>
using namespace std;

// 애매한 점
// 리스트에 중복이 있을것인지

int N, M, A, B, Answer = 0;
bool Visited[501] = {};
unordered_set<int> FriendList[501] = {};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    while (M-- > 0)
    {
        cin >> A >> B;
        FriendList[A].insert(B);
        FriendList[B].insert(A);
    }

    Visited[1] = true;
    for (auto FirstIter : FriendList[1])
    {
        // 상근이의 친구 찾기
        if (Visited[FirstIter] == false)
        {
            Visited[FirstIter] = true;
            Answer++;
        }

        // 상근이 친구의 친구 찾기
        for (auto SecondIter : FriendList[FirstIter])
        {
            if (Visited[SecondIter] == false)
            {
                Visited[SecondIter] = true;
                Answer++;
            }
        }
    }

    cout << Answer << '\n';

    return 0;
}