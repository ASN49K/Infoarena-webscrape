#include<iostream.h>
#include<fstream.h>
#include <stdio.h> 
int t,a,b;
int gcd(int a, int b)
{
    if (!b) 
		return a;
    return gcd(b,a%b);
}
int main()
{
	freopen("cmmdc.in", "r", stdin);
    freopen("cmmdc.out", "w", stdout); 
    scanf("%d %d", &a, &b);
	printf("%d", gcd(a,b));
	return 0;
}