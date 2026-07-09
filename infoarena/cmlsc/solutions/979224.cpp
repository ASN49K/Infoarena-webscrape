#include<stdio.h>

#define MAX(a,b) a>b ? a:b

int A[1025],B[1025],M[1025][1025];
int best[1025];
int main()
{
	int n,m;
	freopen ("cmlsc.in","r",stdin);
	freopen ("cmlsc.out","w",stdout);

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&B[i]);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(A[i] == B[j])
				M[i][j] = M[i-1][j-1]+1;
			else
				M[i][j] = MAX(M[i-1][j],M[i][j-1]);

	printf("%d\n",M[n][m]);

	int cnt=0;
    int r = n; 
	int j = m;
	while(r)
	{
		  if(A[r] == B[j])
			  best[++cnt] = A[r] , r-- , j--;
		  else if (M[r-1][j] > M[r][j-1])
			  r--;
		  else
			  j--;
	}
	for(int i=cnt; i>=1; i--)
		printf("%d ",best[i]);
	
	
}

