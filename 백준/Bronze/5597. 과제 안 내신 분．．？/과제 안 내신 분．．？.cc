#include <iostream>
#include <algorithm>

using namespace std; 

bool StudentNumArray[31] = {};
int Input;

int main()
{
    for (int i = 0; i < 28; ++i)
    {
        cin >> Input;
        StudentNumArray[Input] = true;
    }

    for (int i = 1; i <= 30; ++i)
    {
        if (StudentNumArray[i] == false)
            cout << i << '\n';
    }


    return 0;
}