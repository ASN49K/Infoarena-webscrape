#include <bits/stdc++.h>
using ll=long long;
#define S second
#define F first
#define endl '\n'
#define spid ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod=1e9+7;
const double pi=3.14159265359;
const int maxn=1025;
using namespace std;

int n,m,A[maxn],B[maxn];
int dp[maxn+1][maxn+1];

int main(){
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out"); 
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<m;i++)cin>>B[i];
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int i=0;i<=m;i++)dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(A[i-1]==B[j-1])dp[i][j]=dp[i-1][j-1]+1;
		}
	}
	cout<<dp[n][m]<<endl;
	stack<int> C;
	int i=n,j=m;
	while(i>0&&j>0){
		if(dp[i-1][j]==dp[i][j]){
			i--;
		}
		else if(dp[i][j]==dp[i][j-1])j--;
		else{
			C.push(A[i-1]);
			i--;j--;
		}
	}
	while(C.size()){
		cout<<C.top()<<" ";
		C.pop();
	}
}

