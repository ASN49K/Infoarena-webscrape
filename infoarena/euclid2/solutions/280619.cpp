#include <stdio.h>

int a,b,n; 
 
int cmmdc(int nr1,int nr2)
{
	if (nr2==0)
		return nr1;
	else
		return cmmdc (nr2, nr1%nr2);
}
//-------------------------
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
return 0;
}

