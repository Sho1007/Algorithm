#include <iostream>
using namespace std;

typedef struct FMatrix2x2
{
	long long Matrix[2][2];

	FMatrix2x2()
	{
		Matrix[0][0] = 1; Matrix[0][1] = 1;
		Matrix[1][0] = 1; Matrix[1][1] = 0;
	}
} FMatrix2x2;

FMatrix2x2 MultiplyMatrix(FMatrix2x2 A, FMatrix2x2 B)
{
	FMatrix2x2 Result;

	Result.Matrix[0][0] = ((A.Matrix[0][0] * B.Matrix[0][0]) + (A.Matrix[0][1] * B.Matrix[1][0])) % 1'000'000;
	Result.Matrix[0][1] = ((A.Matrix[0][0] * B.Matrix[0][1]) + (A.Matrix[0][1] * B.Matrix[1][1])) % 1'000'000;
	Result.Matrix[1][0] = ((A.Matrix[1][0] * B.Matrix[0][0]) + (A.Matrix[1][1] * B.Matrix[1][0])) % 1'000'000;
	Result.Matrix[1][1] = ((A.Matrix[1][0] * B.Matrix[0][1]) + (A.Matrix[1][1] * B.Matrix[1][1])) % 1'000'000;

	return Result;
}

FMatrix2x2 Power(FMatrix2x2 Base, long long Exponent)
{
	if (Exponent <= 1) return Base;

	FMatrix2x2 NewBase = Power(Base, Exponent / 2);
	NewBase = MultiplyMatrix(NewBase, NewBase);
	if (Exponent % 2 == 1)
	{
		NewBase = MultiplyMatrix(NewBase, Base);
	}

	return NewBase;
}

long long Fibonacci(long long N)
{
	FMatrix2x2 Matrix2x2;

	Matrix2x2 = Power(Matrix2x2, N);

	return Matrix2x2.Matrix[0][1];
}

long long N;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	cout << Fibonacci(N) << '\n';

	return 0;
}