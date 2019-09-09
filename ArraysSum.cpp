#include <iostream>

using namespace std;

int N;

int* Sum(int* A, int* B, int Asize, int Bsize)
{
	int* pA = A;
	int* pB = B;
	if (Asize < Bsize)
	{
		pA = B;
		pB = A;
		swap(Asize, Bsize);
	}
	int diff = Asize - Bsize;
	int* pC = new int[Asize];
	for (int i = 0; i < Asize; i++)
	{
		while (i < diff)
		{
			pC[i] = 0;
			i++;
		}
		pC[i] = pB[i - diff];
	}
	int* Result = new int[Asize];
	int perenos = 0;
	for (int i = Asize - 1; i >= 0; i--)
	{
		Result[i] = pC[i] + pA[i] + perenos;
		perenos = 0;
		if (Result[i] > 9)
		{
			perenos = 1;
			Result[i] -= 10;
		}
	}
	int* p;
	if (perenos == 1)
	{
		p = new int[Asize + 1];
		p[0] = 1;
		for (int i = 0; i < Asize; i++)
		{
			p[i + 1] = Result[i];
		}
		N = Asize + 1;
		delete[] Result;
	}
	else
	{
		p = &Result[0];
		N = Asize;
	}
	delete[] pC;
	return p;
}

int main()
{
	int A[] = { 1, 0, 3, 9, 0 };
	int B[] = { 6, 2, 1 };
	int Asize = sizeof(A) / 4;
	int Bsize = sizeof(B) / 4;
	int* p = Sum(A, B, Asize, Bsize);
	for (int i = 0; i < N; i++)
	{
		cout << p[i];
	}
	return 0;
}
