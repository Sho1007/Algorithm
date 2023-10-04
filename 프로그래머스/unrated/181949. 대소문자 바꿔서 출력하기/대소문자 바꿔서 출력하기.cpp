#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'a')
        {
            cout << (char)(str[i] - 32);
        }
        else
        {
            cout << (char)(str[i] + 32);
        }
    }
    
    cout << '\n';
    
    return 0;
}