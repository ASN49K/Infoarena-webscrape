#include<stdio.h>
using namespace std;

int v1[1025],v2[1025],m[1025][1025],n,k,rez[1025];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&v1[i]);
	for(int i=1;i<=k;i++)
		scanf("%d",&v2[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
		{
			if(v1[i]==v2[j])
				m[i][j] = m[i-1][j-1]+1;
			else
				m[i][j] = m[i-1][j]>m[i][j-1] ? m[i-1][j]:m[i][j-1];
		}
	printf("%d\n",m[n][k]);
	int cont = 0;
	int i = n, j = k;
	while( i>0 && j>0 )
	{
		if(v1[i] == v2[j])
		{
			rez[++cont] = v1[i];
			i--;j--;
		}
		else
		    m[i-1][j]>m[i][j-1] ? i--:j--;
	}
	for(int i=cont ;i>=1;i--)
	{
		printf("%d ",rez[i]);
	}
	
}
