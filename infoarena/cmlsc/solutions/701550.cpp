#include<fstream>
#include<vector>
#include<algorithm>
#define maxn 1030

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int dp[maxn][maxn];
int a[maxn],b[maxn];
int n,m;
vector<int>sol;

void read()
{
	in>>n>>m;
	for(int i=n;i>=1;i--)
		in>>a[i];
	for(int i=m;i>=1;i--)
		in>>b[i];
}

void solve()
{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
		  if(a[i]==b[j])
		   dp[i][j]=dp[i-1][j-1]+1;
		  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	  }
}
void reconstituie()
{
   int i=n,j=m;
   while(i)
   {
	   if(a[i]==b[j]) out<<a[i]<<" ",i--,j--;
	   else if(dp[i][j-1]<dp[i-1][j]) i--;
	   else j--;
	 
   }
}
int main()
{
	read();
	solve();
	out<<dp[n][m]<<"\n";
	reconstituie();
	
		
	
}

