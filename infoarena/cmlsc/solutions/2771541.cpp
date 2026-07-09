#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1024], b[1024], dp[1024][1024], v[1024];
int main(){
	int m, n; f>>m>>n;
    int a[m]={}, b[n]={};
    for (int i=0; i<m; ++i) f>>a[i];
    for (int i=0; i<n; ++i) f>>b[i];
    int c=0;
    for (int i=0; i<m; ++i){
    	for (int j=0; j<n; ++j){
    		if (a[i]==b[j]){
    			dp[i][j]=dp[i-1][j-1]+1;
    			v[c]+=a[i];
    			++c;
    		}
    		else{
    			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }
    g<<dp[m-1][n-1]<<'\n';
    for (int i=0; i<c; ++i){
    	g<<v[i]<<' ';
    }
    return 0;
}