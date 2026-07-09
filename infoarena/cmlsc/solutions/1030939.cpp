/*
    Keep It Simple!
*/

#define max(a,b) a>b ? a:b

#include<stdio.h>

int n,m,v[1025],w[1025],mat[1025][1025],rez[1025];

int main()
{
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int j=1;j<=m;j++)
		scanf("%d",&w[j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(v[i] == w[j])
				mat[i][j] = mat[i-1][j-1]+1;
			else
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
		}
		
	printf("%d\n",mat[n][m]);
	
	int i=n,j=m,cnt=0;
	while(i > 0 && j  > 0)
	{
		if(v[i] == w[j])
		{
			rez[++cnt] = v[i];
			i--;
			j--;
		}
		else if(mat[i-1][j] > mat[i][j-1]) i--;
		else j--;
	}
	for(int i=cnt;i>0;i--)
		printf("%d ",rez[i]);
}
