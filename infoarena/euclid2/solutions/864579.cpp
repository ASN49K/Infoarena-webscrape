#include <stdio.h>
#include <conio.h>

int A, B, T;

int cmmdc(int a, int b)
{
	if(!b)
		return a;
	else
		return(b, a % b);
}

int main(void)
{

	FILE *f1, *f2;
	f1 = fopen("euclid2.in", "r");
	f2 = fopen("euclid2.out", "w");
	fscanf(f1, "%d", &T);
	for(;T;--T)
	{
		fscanf(f1, "%d %d", &A, &B);
		fprintf(f2, "%d\n", cmmdc(A, B));
	}
	_getch();
}

