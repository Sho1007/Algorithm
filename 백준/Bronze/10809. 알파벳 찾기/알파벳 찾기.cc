#include <iostream>
#include <string>

using namespace std;

string str;

int arr[26];

int main()
{
    for (int i = 0; i < 26; ++i)
    {
        arr[i] = -1;
    }
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        int pos = (int)str[i] - (int)'a';
        if (arr[pos] == -1)
            arr[pos] = i;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}