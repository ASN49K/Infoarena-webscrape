/*
#include <stdio.h>
#include <stdlib.h>

int CMMDC (int a, int b)
{
	if (b == 0) return a;
	return CMMDC (b, a % b);
}

int main (int argc, char const *argv[])
{
	int lines, A, B;

	freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
 	
    
    scanf ("%d", &lines);
    while (lines)
    {
        scanf ("%d %d", &A, &B);
        printf("%d\n", CMMDC (A, B));
    }   
	return 0;
}*/
#include <stdio.h>
 
int T, A, B;
 
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
 
int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
 
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }        
}