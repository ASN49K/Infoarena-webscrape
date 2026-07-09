using namespace std;
#include<cstdio>
#include<algorithm>
#define nmax 1025
int dp[nmax][nmax],i,j,n,m,k,sol[nmax];
int a[nmax],b[nmax];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	i=n; j=m; k=0;
	while(dp[i][j])
	{
		if(a[i]==b[j]) {sol[k++]=a[i];i--;j--;}
		else if(dp[i][j]==dp[i-1][j]) i--;
			else j--;
	}
	/*for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			printf("%d ",dp[i][j]);
	*/
	printf("%d\n",dp[n][m]);
	for(i=k-1;i>=0;i--)
		printf("%d ",sol[i]);
	return 0;
}