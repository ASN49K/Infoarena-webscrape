#include <stdio.h>

int cmmdc(int a,int b)
{
	if (b==0) return a;
	return cmmdc(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	int a,b,t;
	
	scanf("%d", &t);
	
	while (t--) scanf("%d%d", &a,&b), printf("%d\n", cmmdc(a,b));

	return 0;
}
