
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int Gcd (int A, int B)
{
	if (!B) 
	{
		return A;
	}
	return Gcd(B, A % B);
}

int main(void)
{
	FILE * In = fopen("euclid2.in", "r");
	if (!In)
	{ 
		return 0;
	}
	FILE * Out = fopen("euclid2.out", "w"); 
	if (!Out)
	{ 
		return 0;
	}

	int number = 0, first, second, result;
	scanf("%d", &number);

	for (int i = 0; i < number; i += 1)
	{
		scanf("%d %d", &first, &second);
		result = Gcd(first, second);
		fprintf(Out, "%d", result);
	}

	fclose(In);
	fclose(Out);
	
	return 0;
}

