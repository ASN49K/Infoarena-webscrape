#include<stdio.h>
#define nmax 1025
#define maxim(a, b) ((a > b) ? a : b)  
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
int a1[nmax], a2[nmax], n,m, i, j,dp[nmax][nmax],sir[nmax];

int main()
{
	fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;++i) fscanf(f,"%d",&a1[i]);
	for(j=1;j<=m;++j) fscanf(f,"%d",&a2[j]);

	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a1[i]==a2[j]) dp[i][j]=1+dp[i-1][j-1];
		else dp[i][j]=maxim(dp[i-1][j],dp[i][j-1]);
	
	int k=0;
	i=n;
	j=m;
	while(i)
	{
		
		if(a1[i]==a2[j])
		{
			sir[++k]=a1[i];
			i--;
			j--;
		}
		else
			if(dp[i][j-1]>dp[i-1][j]) j--;
		else
			i--;
	}
	
	fprintf(g,"%d\n",k);
	for(i=k;i>=1;--i) fprintf(g,"%d ",sir[i]);
	fprintf(g,"\n");
	fclose(g);
	return 0;
}