#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

int n,m,a[1025], b[1025], dp[1025][1025];
vector<int> sol;

int main(void) {
    ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	
	cin>>n>>m;
	
	for (int i=1; i<=n; ++i) cin>>a[i];
	for (int i=1; i<=m; ++i) cin>>b[i];
	
	for (int i=1; i<=n; ++i)
	 for (int j=1; j<=m; ++j)
	  if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
	  else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	  
	cout<<dp[n][m]<<"\n";	
	
	int i=n, j=m;
	
	while (i>0 && j>0) {
	  if (a[i]==b[j]) {sol.push_back(a[i]); --i; --j;}
	  else if (dp[i-1][j]>dp[i][j-1]) --i;
	  else --j;	
	}
	
	for (int i=sol.size()-1; i>=0; --i) cout<<sol[i]<<" ";
	
	return 0;
}
