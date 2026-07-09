#include <cstdio>

using namespace std;
int w[100][100],b[100],a[100],n,m,i,j,max,k,vec[100];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for(i=1; i<=n; i++)
		for(j=1; j<=m ;j++)
		{
			if(a[i]==b[j])
				w[i][j]=w[i-1][j-1]+1;
			else
			{
				if(w[i-1][j]>w[i][j-1])
					w[i][j]=w[i-1][j];
				else
					w[i][j]=w[i][j-1];
			}
		}
	printf("%d\n",w[n][m]);
	max=w[n][m];
	i=n+1;	j=m+1;
	k=1;
	while(w[i][j]!=0)
	{
		if(w[i-1][j]==w[i][j-1])
			{
				i--; j--;
				if(a[i]==b[j])
					{
						vec[k]=a[i];
						k++;
					}
			}
		else
		{
			if(w[i-1][j]>w[i][j-1])
			{
				i--;
				if(a[i]==b[j])
				{
					vec[k]=a[i];
					k++;
				}
			}
			if(w[i-1][j]<w[i][j-1])
			{
				j--;
				if(a[i]==b[j])
				{
					vec[k]=a[i];
					k++;
				}
			}
		}
	}
	for(i=max;i>0;i--)
		printf("%d ",vec[i]);
	return 0;
}