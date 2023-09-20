#include <iostream>
using namespace std;

/*
	13116. 30번
	A, B가 주어졌을 때, 그 공통 부모 중 최대값의 10배를 출력
	완전 이진 트리 기준
	자식 Index 구하는 공식 -> LeftChild = (Index * 2 + 1) , RightChild = (Index * 2 + 2)
	즉 역순으로 부모 구하는 공식 -> 홀수면(왼쪽자식) = (Index - 1) / 2; 짝수면(오른쪽 자식) = (Index - 2) / 2;

	// -> 1부터 시작함
	왼쪽은 *2, 오른쪽은 *2 + 1
	왼쪽에서 부모는 Index / 2, 오른쪽에서 부모는 (Index-1) / 2

*/

int GetParentIndex(int ChildIndex)
{
	if (ChildIndex % 2 == 0) return ChildIndex / 2;
	return (ChildIndex - 1) / 2;
}

int T, A, B;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;

	while (T-- > 0)
	{
		cin >> A >> B;
		while (A != B)
		{
			if (A > B)
			{
				A = GetParentIndex(A);
			}
			else
			{
				B = GetParentIndex(B);
			}
		}

		cout << A * 10 << '\n';
	}

	return 0;
}