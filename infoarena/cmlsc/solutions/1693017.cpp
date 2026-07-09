#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,a[1050],b[1050],dp[1050][1050],rs[1050],r;

int main(){
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=m; i++) cin >> b[i];
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
								else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	
	int i=n, j=m;
	
	while(i) if(a[i]==b[j])rs[++r]=a[i],i--,j--;
			 else if(dp[i-1][j]<dp[i][j-1])
			 	  j--;
				  else i--; 		
	
	cout << r << '\n';
	for(i=r; i; i--) cout << rs[i] << " ";
	
return 0;
}
