#include<stdio.h>
#define NMAX 1030
int a[NMAX][NMAX],n,m,MAX=0,mx,my,ind,traseu[1024];
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
	if(x>=y)return x;
	return y;
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
			a[i][j]=1+a[i-1][j-1];
			if(a[i][j]>MAX)
			{
			MAX=a[i][j];mx=i;my=j;
			}	
		}		
		else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
	}
	for(i=n+1,j=m+1,ind=0;i>0&&j>0&&ind<MAX;)
	{
		if(a[i][0]==a[0][j]){traseu[ind++]=a[i][0];--i;--j;}
		else if(a[i-1][j]>=a[i][j-1])--i;
			 else --j;
	}
	for(ind;ind>0;--ind)
		fprintf(g,"%d ",traseu[ind-1]);
	fclose(g);
	return 0;
}
