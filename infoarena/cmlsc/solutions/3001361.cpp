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
int dp[maxn][maxn];

int main(){
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out"); 
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>A[i];
	for(int i=0;i<m;i++)cin>>B[i];
	if(A[0]==B[0])dp[0][0]=1;
	else dp[0][0]=0;
	for(int i=1;i<n;i++){
		if(A[i]==B[0])dp[i][0]=1;
		else dp[i][0]=dp[i-1][0];
	}
	for(int i=1;i<m;i++){
		if(A[0]==B[i])dp[0][i]=1;
		else dp[0][i]=dp[0][i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(A[i]==B[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/
	cout<<dp[n-1][m-1]<<endl;
	stack<int> C;
	int i=n-1,j=m-1;
	while(i>0&&j>0){
		if(dp[i-1][j]==dp[i][j]){
			i--;
		}
		else if(dp[i][j]==dp[i][j-1])j--;
		else{
			C.push(A[i]);
			i--;j--;
		}
	}
	while(i>0){
		if(dp[i][0]>dp[i-1][0]){
			C.push(A[i]);
		}
		i--;
	}
	while(j>0){
		if(dp[0][j]>dp[0][j-1]){
			C.push(B[j]);
		}
		j--;
	}
	if(A[0]==B[0])C.push(A[0]);
	while(C.size()){
		cout<<C.top()<<" ";
		C.pop();
	}
}

