#include<stdio.h>
#define NMAX 1030
int a[NMAX][NMAX],n,m,max[NMAX][NMAX],MAX=0,traseu[1026],ind;
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
int main()
{
	read();
	int i,j;
	for(i=2;i<=n+1;++i)
	for(j=2;j<=m+1;++j)
	{
		max[i][j]=maxim(max[i-1][j],max[i][j-1]);
		if(a[i][0]==a[0][j])
		{
			a[i][j]=1+max[i-1][j-1];
			max[i][j]=maxim(max[i][j],a[i][j]);
		}
		if(max[i][j]>MAX)
		{
			MAX=max[i][j];
			traseu[ind++]=a[i][0];
		}
	}
	fprintf(g,"%d\n",MAX);
	for(i=0;i<ind;++i)
		fprintf(g,"%d ",traseu[i]);
	fclose(g);
	return 0;
}
