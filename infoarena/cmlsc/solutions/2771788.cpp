#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024], b[1024], dp[1024][1024], v[1024];
int main(){
	int m, n; fin>>m>>n;
    for (int i=0; i<m; ++i) fin>>a[i];
    for (int i=0; i<n; ++i) fin>>b[i];
    int c=0;
    for (int i=0; i<m; ++i){
    	for (int j=0; j<n; ++j){
    		if (a[i]==b[j]){
    			dp[i][j]=dp[i-1][j-1]+1;
    			v[c]=a[i];
    			++c;
    		}
    		else{
    			dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    }
    fout<<c<<'\n';
    for (int i=0; i<c; ++i){
    	fout<<v[i]<<' ';
    }
    return 0;
}