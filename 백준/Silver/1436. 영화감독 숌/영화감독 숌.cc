#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int nowCount = 1;

void Check(int nowNum)
{
	if (nowCount == N)
	{
		cout << nowNum << endl;
		return;
	}
		

	nowNum++;
	// 하나 더 큰 수 돌면서
	for (;; nowNum++)
	{
		// 666이 들어가있는지 체크하기
		string str = to_string(nowNum);
		// 666이 있으면
		if (str.find("666") != string::npos)
		{
			nowCount++;
			Check(nowNum);
			return;
		}
	}
}

int main()
{
	scanf("%d", &N);

	int num = 666;

	Check(num);

	return 0;
}