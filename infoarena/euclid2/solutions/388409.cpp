#include<stdio.h>

int i,j,n,a,b;

int cmmdc(int a,int b)
{
	if(b==0) return a;
	return cmmdc(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&n);
	
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		int k=cmmdc(a,b);
		printf("%d\n",k);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
