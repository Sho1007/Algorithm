#include <iostream>
using namespace std;

int N;
pair<char, char> arr[26] = {};

void PreOrder(int num)
{
	cout << char(num + 'A');
	if (arr[num].first != '.') PreOrder(arr[num].first - 'A');
	if (arr[num].second != '.') PreOrder(arr[num].second - 'A');
	if (!num) cout << endl;
}
void InOrder(int num)
{
	if (arr[num].first != '.') InOrder(arr[num].first - 'A');
	cout << char(num + 'A');
	if (arr[num].second != '.') InOrder(arr[num].second - 'A');
	if (!num) cout << endl;
}
void PostOrder(int num)
{
	if (arr[num].first != '.') PostOrder(arr[num].first - 'A');
	if (arr[num].second != '.') PostOrder(arr[num].second - 'A');
	cout << char(num + 'A');
	if (!num) cout << endl;
}

int main()
{
	cin >> N;
	
	char parent, left, right;
	while (N-- > 0)
	{
		cin >> parent >> left >> right;
		arr[parent - 'A'].first = left;
		arr[parent - 'A'].second = right;
	}

	PreOrder(0);
	InOrder(0);
	PostOrder(0);

	return 0;
}