#include<stdio.h>
#define Nmax 1026
using namespace std;

FILE *c,*d;
int m,n,a[Nmax],b[Nmax],dp[Nmax][Nmax],drum[Nmax],ndrum;

int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}

void read()
{
	int i;
	fscanf(c,"%d %d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(c,"%d",&a[i]);
	for(i=1;i<=n;i++)
		fscanf(c,"%d",&b[i]);
}

void dynamic()
{
	int i,j;
	for(i=0;i<=m;i++)
		dp[i][0]=0;
	for(i=0;i<=n;i++)
		dp[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				ndrum++;
				drum[ndrum]=a[i];
			}	
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}

int main()
{
	c=fopen("cmlsc.in","r");
	d=fopen("cmlsc.out","w");
	int i;
	ndrum=0;
	read();
	dynamic();
	fprintf(d,"%d\n",ndrum);
	for(i=1;i<=ndrum;i++)
		fprintf(d,"%d ",drum[i]);
	fclose(c);
	fclose(d);
	return 0;
}
	