#include <stdio.h>
#define NMax 1024
const char IN[]   ="cmlsc.in";
const char OUT[]  ="cmlsc.out";

int N,M;
int a[NMax+10],b[NMax+10];
int m[2][NMax+10];
int p1,p2;

int max(int x,int y)
{
	return (x>y) ? x : y;
}

int cmlsc()
{
	int i,j;
	p1=0;p2=1;
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
			if (a[i]==b[j])
				m[p1][j]= (j) ? m[p2][j-1]+1 : 1;
			else
				m[p1][j]= max( (j) ? m[p1][j-1] : 0,m[p2][j]);
		int tmp= p1; p1=p2; p2=tmp;
	}
	return m[p2][M-1];
}

void scriere(int x)
{
	int i;
	freopen(OUT,"w",stdout);
	printf("%d\n",x);
	if (m[p2][0])
		printf("%d ",b[0]);
	for (i=1;i<M;i++)
		if ( i && m[p2][i]>m[p2][i-1])
			printf("%d ",b[i]);
	printf("\n");
	fclose(stdout);
}

void citire()
{
	int i;
	freopen(IN,"r",stdin);
	scanf("%d%d",&N,&M);
	for (i=0;i<N;i++)
		scanf("%d",&a[i]);
	for (i=0;i<M;i++)
		scanf("%d",&b[i]);
	fclose(stdin);
}

int main()
{
	citire();
	scriere(cmlsc());
	return 0;
}
