#include <bits/stdc++.h>
using namespace std;
long long a[1025],b[1025],dp[1025][1025],n,m,sir[1024],i,j,res;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	cin >> m >> n ;
	for (i=1;i<=m;i++)cin >> a[i];
	for (i=1;i<=n;i++)cin >> b[i];
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (a[i]==b[j])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	
	for (i=m,j=n;i;)
	{
		if (a[i]==b[j])
		{
		sir[++res]=a[i],--i,--j;	
		}
		else if (dp[i-1][j]<dp[i][j-1])--j;
		else --i;
	}
	cout << res << "\n";
	for (i=res;i>0;i--)
	{
		cout << sir[i]<<" ";
		
	}
	cout << "\n";
    return 0;
}
