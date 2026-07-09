#include <stdio.h>
#define MAXN 1030
#define MAXM 1030 
int v[MAXN][MAXM],n,m;
int vn[MAXN],vm[MAXM],R[MAXN];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	int i,j,rez=0;
	
	scanf("%d%d",&n,&m);
	
	for (i=0; i<n; i++)
		scanf("%d",&vn[i]);
	for (i=0; i<m; i++)
		scanf("%d",&vm[i]);
	
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (vn[i-1]==vm[j-1])
				v[i][j]=v[i-1][j-1]+1;
			else
				if (v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];
	
	for (i=n, j=m, rez=0; j>0 && i>0;)
		if (vn[i-1]==vm[j-1])
		{
			R[rez++]=vn[i-1];
			i--; j--;
		}
		else
			if (v[i][j]>v[i][j-1])
				i--;
			else
				j--;
	
	printf("%d\n",rez);
	for (i=rez-1; i>0; i--)
		printf("%d ",R[i]);
	printf("%d\n",R[0]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
