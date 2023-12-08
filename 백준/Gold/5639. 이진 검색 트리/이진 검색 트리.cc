#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void PostOrder(int startPos, int endPos)
{
    if (startPos == endPos)
    {
        cout << v[startPos] << '\n';
        return;
    }
    
    int root = v[startPos];
    int leftEnd = -1;
    for (int i = startPos + 1; i < endPos; ++i)
    {
        if (v[i] < root) leftEnd = i;
        else break;
    }
    if (leftEnd != -1) PostOrder(startPos + 1, leftEnd + 1);
    int rightStart = -1;
    for (int i = startPos + 1; i < endPos; ++i)
    {
        if (v[i] > root)
        {
            rightStart = i;
            break;
        }
    }
    if (rightStart != -1) PostOrder(rightStart, endPos);
    cout << root << '\n';
    return;
}

int main()
{
    int num;
    while (!cin.eof())
    {
        cin >> num;
        v.push_back(num);
    }
    
    PostOrder(0, v.size());
    
    return 0;
}