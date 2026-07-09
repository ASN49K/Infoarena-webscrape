#include<stdio.h>
#define NMAX 1030
int a[NMAX][NMAX],n,m,MAX=0,mx,my;
FILE*g=fopen("cmlsc.out","w");
void read()
{
	FILE*f=fopen("cmlsc.in","r");
	fscanf(f,"%d%d",&n,&m);
	int i;
	a[1][1]=0;
	for(i=2;i<=n+1;++i)
	fscanf(f,"%d",&a[i][0]);
	
	for(i=2;i<=m+1;++i)
		fscanf(f,"%d",&a[0][i]);
	fclose(f);
}
int maxim(int x,int y)
{
	if(!MAX)return 0;
	if(mx<x&&my<y)return MAX;
	int max=0,j;
	for(;x>=2;--x)
	for(j=y;j>=2;--j)
		if(a[x][j]>max)max=a[x][j];
	
	return max;
}
void drum(int x,int y,int var)
{
	if(!var)return;
	int i,j;
	for(i=x;i>=0;--i)
	for(j=y;j>=0;--j)
	{
		if(a[i][j]==var)
		{
			drum(i-1,j-1,var-1);
			fprintf(g,"%d ",a[i][0]);
			j=i=-1;
		}
	}
}
int main()
{
	read();
	int i,j;
	for(i=2;i<=n+1;++i)
	for(j=2;j<=m+1;++j)
	{
		if(a[i][0]==a[0][j])
		{
			a[i][j]=1+maxim(i-1,j-1);
			if(a[i][j]>MAX)
			{
			MAX=a[i][j];mx=i;my=j;
			}	
		}		
	}
	fprintf(g,"%d\n",MAX);
	drum(mx,my,MAX);
	fclose(g);
	return 0;
}
