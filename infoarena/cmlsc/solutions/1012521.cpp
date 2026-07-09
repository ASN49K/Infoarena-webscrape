/*
          ~Keep It Simple!~
*/

#include<stdio.h>

int mat[1025][1025],v1[1025],v2[1025],rez[1025],countel;

#define max(a,b) a>b?a:b

int main()
{
	int n,m;

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v1[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&v2[i]);
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(v1[i] == v2[j])
				mat[i][j] = mat[i-1][j-1] + 1;
			else
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
		}
	printf("%d\n",mat[n][m]);

   int i = n, j = m;
   while( i>0 && j>0 )
		{
			if(v1[i] == v2[j])
				rez[++countel] = v1[i],i--,j--;
			else
				if(  max(mat[i-1][j],mat[i][j-1]) ==  mat[i-1][j] )
					i--;
				else 
					j--;
		}
    for(int i=countel;i>0;i--)
		printf("%d ",rez[i]);
}