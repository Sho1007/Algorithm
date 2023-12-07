#include <iostream>

using namespace std;

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    unsigned int N, K;
    unsigned int *arr;

    cin >> N >> K;
    
    arr = new unsigned int[N+1];

    unsigned int left = 1, mid, right = 0;
    for (unsigned int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        if (arr[i] > right)
            right = arr[i];
    }

    unsigned int answer = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        
        unsigned int cnt = 0;
        for (unsigned int i = 1; i <= N; ++i) cnt += arr[i] / mid;
        if (cnt >= K) answer = mid, left = mid + 1;
        else right = mid - 1;
    }
    cout << answer << endl;
    
    delete[] arr;

    return 0;
}