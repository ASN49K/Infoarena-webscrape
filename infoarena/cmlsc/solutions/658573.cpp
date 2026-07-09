#include<stdio.h>
#define Nmax 1026
using namespace std;

FILE *c,*d;
short int m,n,a[Nmax],b[Nmax],dp[Nmax][Nmax],path[Nmax][Nmax];



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
			if(a[i]==b[j])                                        // 1- i-1,j-1 stanga sus,2- i-1,j sus,3- i,j-1 stanga
			{
				dp[i][j]=dp[i-1][j-1]+1;
				path[i][j]=1;
			}	
			else
				if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j];
					path[i][j]=2;
				}
				else
				{
					dp[i][j]=dp[i][j-1];
					path[i][j]=3;
				}
}

void view_path(int i,int j)
{
	if(path[i][j]!=0)
		if(path[i][j]==1)
		{
			view_path(i-1,j-1);
			fprintf(d,"%d ",a[i]);
		}
		else
			if(path[i][j]==2)
				view_path(i-1,j);
			else
				view_path(i,j-1);
}

int main()
{
	c=fopen("cmlsc.in","r");
	d=fopen("cmlsc.out","w");
	read();
	dynamic();
	fprintf(d,"%d\n",dp[m][n]);
	view_path(m,n);
	fclose(c);
	fclose(d);
	return 0;
}
	