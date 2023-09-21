#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int T, n;
string p, x;
int arr[100'000] = {};

void CheckNum(bool& isFront, int& frontNum, int& endNum)
{
    for (int i = 0; i < p.length(); ++i)
    {
        // Find R 
        int j = i;
        while (j < p.length() && p[j] == 'R')
        {
            j++;
        }
        // R이 있는 경우
        if (j != i)
        {
            // R이 홀수개인 경우
            if ((j - i) % 2 != 0)
            {
                isFront = !isFront;
            }
        }
        // Find D
        int k = j;
        while (k < p.length() && p[k] == 'D')
        {
            k++;
        }
        // D가 있는 경우
        if (k != j)
        {
            if (isFront) frontNum += k - j;
            else endNum += k - j;
        }
        i = k - 1;
    }
}

void SplitX()
{
    int pos = 0;
    x = x.substr(1, x.length() - 2);
    int start = 0;
    int next = x.find(',', start);
    while (next != string::npos)
    {
        string str = x.substr(start, next - start);
        if (str.length() > 1)
            arr[pos++] = stoi(str);
        else
            arr[pos++] = str[0] - '0';
        
        start = next + 1;
        next = x.find(',', start);
    }
    string str = x.substr(start, next - start);
    if (str.length() > 1)
        arr[pos++] = stoi(str);
    else
        arr[pos++] = str[0] - '0';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while (T-- > 0)
    {
        cin >> p >> n >> x;

        bool isFront = true;
        int frontNum = 0, endNum = 0;
        CheckNum(isFront, frontNum, endNum);

        if (frontNum + endNum > n)
        {
            cout << "error" << endl;
            continue;
        }

        
        if (n == 0) cout << "[]" << endl;
        else
        {
            SplitX();
            string answer = "[";
            if (isFront)
            {
                for (int i = frontNum; i < n - endNum; ++i)
                {
                    answer += to_string(arr[i]);
                    if (i != n - endNum - 1)
                        answer += ',';
                }
            }
            else
            {
                for (int i = n - endNum - 1; i >= frontNum; --i)
                {
                    answer += to_string(arr[i]);
                    if (i != frontNum)
                        answer += ',';
                }
            }
            answer += ']';

            cout << answer << endl;
        }
    }

    return 0;
}