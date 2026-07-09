#include<stdio.h>
#define NMAX 1030
int a[NMAX][NMAX],n,m,max[NMAX][NMAX][2],MAX=-99999;
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
int maxim(int a,int b)
{
	if(a>=b)return a;
	return b;
}
void drum(int x,int y,int var)
{
	if(!var)return;
	int i,j;
	for(i=x;i>=0;--i)
	for(j=y;j>=0;--j)
	{
		if(max[i][j][0]==var)
		{
			drum(i-1,j-1,var-1);
			fprintf(g,"%d ",max[i][j][1]);
			j=i=-1;
		}
	}
}
int main()
{
	read();
	int i,j,x,y;
	for(i=2;i<=n+1;++i)
	for(j=2;j<=m+1;++j)
	{
		if(max[i][j-1][0]>=max[i-1][j][0])
		{
			max[i][j][0]=max[i][j-1][0];
			max[i][j][1]=max[i][j-1][1];
		}
		else
		{
			max[i][j][0]=max[i-1][j][0];
			max[i][j][1]=max[i-1][j][1];
		}
		if(a[i][0]==a[0][j])
		{
			a[i][j]=1+max[i][j][0];
			if(a[i][j]>=max[i][j][0])
			{
				max[i][j][0]=a[i][j];
				max[i][j][1]=a[i][0];
			}
		}
		if(max[i][j][0]>MAX){MAX=max[i][j][0];x=i;y=j;}
	}
	fprintf(g,"%d\n",MAX);
	drum(x,y,MAX);
	fclose(g);
	return 0;
}