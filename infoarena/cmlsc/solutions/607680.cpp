#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int i,j,n,m,a[1025],b[1025],dp[1025][1025];
void scriere(short i,short j)
{	
	if(dp[i][j]>0)
	{
		if((dp[i-1][j-1]+1)==dp[i][j] && a[i]==b[j])
		{ 
		scriere(i-1,j-1);
		cout<<a[i]<<" ";
		}
		else
			if(dp[i-1][j]==dp[i][j])
			{
				scriere(i-1,j);
			}
			else scriere(i,j-1);
	}

}

int main()
{
	freopen("cmlsc.in","r", stdin);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(j=1;j<=m;j++) scanf("%d",&b[j]);
	fclose(stdin);
	
	for(i=1;i<=n;i++) 
	{	for(j=1;j<=m;j++)
		{
			if(a[i]==b[j]) 
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
		
 			if( max(dp[i-1][j],dp[i][j-1])>dp[i][j] )
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			
			//printf("%d ",dp[i][j]);
		}
	//printf("\n");
	}
	freopen("cmlsc.out","w", stdout);
	
	cout<<dp[n][m];
	cout<<"\n";
	scriere(n,m);

	fclose(stdout);
	return 0;
}
