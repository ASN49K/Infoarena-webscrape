#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

int A[1028], B[1028];
int C[1028][1028], sir[1028];
int lungimeA, lungimeB;
int counter;

int maxim(int a, int b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &lungimeA, &lungimeB);

	for(int i = 1; i <= lungimeA; ++i)
	{
		scanf("%d", &A[i]);
	}

	for(int i = 1; i <= lungimeB; ++i)
	{
		scanf("%d", &B[i]);
	}

	// gasim lungimea maxima a subsirului comun
	for(int i = 1; i <= lungimeA; ++i)
	{
		for(int j = 1; j <= lungimeB; ++j)
		{
			// daca e element comun incrementam lungimea sirului comun cu 1
			if(A[i] == B[j])
			{
				C[i][j] = C[i-1][j-1] + 1;
			}
			// daca difera, la pozitia C[i][j] se afla maximul dintre elementele din sus sau stanga
			else
			{
				C[i][j] = maxim(C[i-1][j], C[i][j-1]);
			}
		}
	}

	// afisam lungimea maxima
	printf("%d\n", C[lungimeA][lungimeB]);

	// pornim de la ultimul element cu gasirea sirului
	int iteratorPrimulSir = lungimeA;
	int iteratorAlDoileaSir = lungimeB;

	counter = 0;

	// o luam invers, daca A[i] == A[j] mergem pe diagonala, daca nu mergem pe pozitia in care C este mai mare din sus sau stanga pana ajungem pe prima linie sau coloana
	// salvam numerele in sir in ordine inversa ca apoi sa il afisam corect
	while(iteratorPrimulSir > 0 && iteratorAlDoileaSir > 0)
	{
		if(A[iteratorPrimulSir] == B[iteratorAlDoileaSir])
		{
			sir[counter] = A[iteratorPrimulSir];
			counter++;
			iteratorPrimulSir--;
			iteratorAlDoileaSir--;
		}
		else
		{
			if(C[iteratorPrimulSir-1][iteratorAlDoileaSir] > C[iteratorPrimulSir][iteratorAlDoileaSir-1])
				iteratorPrimulSir--;
			else
				iteratorAlDoileaSir--;
		}
	}

	for(int i = counter - 1; i >= 0; --i)
	{
		printf("%d ", sir[i]);
	}

	return 0;
}