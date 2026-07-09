#include <stdio.h>
#define NMax 1024
const char IN[]   ="cmlsc.in";
const char OUT[]  ="cmlsc.out";

int N,M;
int a[NMax+10],b[NMax+10];
int D[NMax+10][NMax+10];
int Sol[NMax+10];

int max(int x,int y)
{
	return (x>y) ? x : y;
}

int cmlsc()
{
	int i,j;int Mx=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
			if (a[i]==b[j])
				D[i][j]= (j && i) ? D[i-1][j-1]+1 : 1;
			else
				D[i][j]= max( (j) ? D[i][j-1] : 0, (i) ? D[i-1][j] : 0);
	}
	for (i=N-1,j=M-1;i>=0;)
	{
		if (a[i]==b[j])
			Sol[Mx++]= a[i], i--,j--;
		else if (( (i) ? D[i-1][j] : 0)<( (j) ? D[i][j-1] : 0))
			j--;
		else
			i--;
	}
	return Mx;
}

void scriere(int x)
{
	int i;
	freopen(OUT,"w",stdout);
	printf("%d\n",x);
	for (x=x-1;x>=0;x--)
		printf("%d ",Sol[x]);
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
