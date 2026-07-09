#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
vector<int> a, b;

// dp[i][j] - LCS of a[i..], b[j..]
// dp[i][j] = 1 + dp[i+1][j+1] if a[i] == b[j]
// otherwise, dp[i][j] = max(dp[i+1][j], dp[i][j+1])
vector<vector<int>> dp;

void read() {
	in>>n>>m;
	a.resize(n);
	b.resize(m);

	for(int i=0;i<n;i++){
		in>>a[i];
	}
	for(int i=0;i<m;i++){
		in>>b[i];
	}
	dp.resize(n+1);
	for (int i =0;i<=n;i++){
		dp[i].resize(m+1);
	}
}

void solve(){
	for(int i = n-1; i >=0; i--){
		for(int j=m-1; j>=0; j--){
			if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i+1][j+1];
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
			}
		}	
	}
	out<<dp[0][0]<<endl;

	int posy = 0, posx = 0;
	vector<int> result;

	while (posy < n && posx < m) {
		if (a[posy] == b[posx]) {
			result.push_back(a[posy]);
			posy++;
			posx++;
		} else{
			if (dp[posy][posx+1] > dp[posy+1][posx]) {
				posx++;
			} else{
				posy++;
			}
		}
	}

	for(int k: result)
		out<<k<<" ";
}

int main() {
	read();
	solve();
	return 0;
}
