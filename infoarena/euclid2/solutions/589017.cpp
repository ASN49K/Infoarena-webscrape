/*#include <stdio.h> 
int T, A, B;
int gcd(int a, int b)
{
    if (!b) 
		return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout); 
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }       
    return 0;
}*/
#include<iostream.h>
#include<fstream.h>
fstream f("euclid2.in",ios::in), g("euclid2.out",ios::out);
int t,a,b;
int gcd(int a, int b)
{
    if (!b) 
		return a;
    return gcd(b,a%b);
}
int main()
{
	f>>t;
	for(;t;--t)
	{
		f>>a>>b;
		g<<gcd(a,b)<<endl;
	}
	return 0;
}