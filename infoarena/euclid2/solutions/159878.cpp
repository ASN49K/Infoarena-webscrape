//Arhiva educationala - Euclid2
#include <stdio.h>
#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"

int T, A, B;


int cmmdc(int A, int B)
{
	while(A && B)
	{
		if(A > B) A %= B;
		else B %=A;
	}
	if(A) return A;
	return B;
}


int main()
{
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	
	scanf("%d", &T);
	
	int i;
	for(i = 1; i <= T; ++i)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", cmmdc(A, B));
	}
	return 0;
}
