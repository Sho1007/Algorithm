#include <stdio.h>
#include <queue>
using namespace std;

inline int Abs(int a) { return a < 0 ? -a : a; }
inline int Min(int a, int b) { return a < b ? a : b; }
struct cmp
{
    bool operator()(int a, int b)
    { 
        if (Abs(a) == Abs(b))
            return a > b;
        return Abs(a) > Abs(b);
    }
}; 

int main()
{
    priority_queue<int, vector<int>, cmp> pq;
    int N, num;
    scanf("%d", &N);
    while (N-- > 0)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            if (pq.empty()) printf("0\n");
            else { printf("%d\n", pq.top()); pq.pop(); }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}