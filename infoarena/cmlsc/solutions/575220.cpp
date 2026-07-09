#include <stack>
#include <stdio.h>
using namespace std;
#define N 1025
int a[N],b[N];
int mat[N][N];
int main ()
{	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;i++)
	{	scanf("%d",&a[i]);
	}
	for (j=1;j<=m;j++)
	{	scanf("%d",&b[j]);
	}
	for (i=1;i<=n;i++)
	{	for (j=1;j<=m;j++)
		{	if(a[i]==b[j])
			{	mat[i][j]=1+mat[i-1][j-1];
			}
			if(mat[i-1][j]>mat[i][j])
			{	mat[i][j]=mat[i-1][j];
			}
			if(mat[i][j-1]>mat[i][j])
			{	mat[i][j]=mat[i][j-1];
			}
		}
	}
	stack<int> s;
	printf("%d\n",mat[n][m]);	
	i=n;j=m;
	for (int k=mat[n][m];k>=1;k--)
	{	while(mat[i-1][j]==k)
			i--;
		while(mat[i][j-1]==k)
			j--;
		s.push(a[i]);
		i--;j--;
	}
	while(!s.empty())
	{
		printf("%d ",s.top());
		s.pop();
	}
	return 0;
}
