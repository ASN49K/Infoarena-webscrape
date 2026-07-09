#include<stdio.h>
int n,m,c[1030],d[1030],mat[1030][1030],i,j,i1,j1;
int max(int a, int b)
{
	if(a>b) return a;
	return b;
}
int st[260],ns=-1;
void afisare()
{
	int i;
	for(i=ns;i>=1;--i)
		printf("%d ",st[i]);
	printf("\n");
}
void solutie(int i, int j, int l)
{
	st[++ns]=c[i+1];
	if(l==0) afisare();
	else
	{
		for(i1=i;i1>=1;i1--)
			for(j1=j;j1>=1;j1--)
				if(mat[i1][j1]==l && c[i1]==d[j1]) 
					solutie(i1-1,j1-1,l-1);
	}
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) scanf("%d",&c[i]);
	for(i=1;i<=m;++i) scanf("%d",&d[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(c[i]==d[j]) mat[i][j]=mat[i-1][j-1]+1;
			else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
	printf("%d\n",mat[n][m]);
	solutie(n,m,mat[n][m]);
	return 0;
}
