#include <stdio.h>
int n,A,B;
int euclid(int,int);
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for( ; n;--n)
	{
		scanf("%d %d",&A,&B);
		printf("%d\n",euclid(A,B));
	}
	return 0;
	fclose(stdin);fclose(stdout);
}
int euclid(int a,int b)
{
	if(!b) return a;
	else return euclid(b,a%b);
}

