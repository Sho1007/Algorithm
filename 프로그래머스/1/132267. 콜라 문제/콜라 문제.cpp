#include <string>
#include <vector>

using namespace std;

int GiveCola;
int ReceiveCola;

int solution(int a, int b, int n) {
    int answer = 0;
    
    // 준 콜라 = n / a;
    // 받은 콜라 = b * (n / a);
    
    while (true)
    {
        GiveCola = (n / a) * a;
        if (GiveCola == 0) break;
        ReceiveCola = b * (n / a);
        answer += ReceiveCola;
        n = (n - GiveCola) + ReceiveCola;
    }
    
    return answer;
}