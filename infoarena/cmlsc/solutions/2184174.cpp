#include<bits/stdc++.h>
#define NMAX 1030
using namespace std;

int DP[NMAX][NMAX];
int a[NMAX],b[NMAX];
int n,m;
stack<int>Q;

int main() {
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int j=1; j<=m; j++) cin>>b[j];
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i]==b[j]) DP[i][j]=DP[i-1][j-1]+1;
			else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
		}
	}
	cout<<DP[n][m]<<'\n';
	
	for (int i=n, j=m; i && j; ) {
		if (a[i]==b[j]) Q.push(a[i]), i--,j--;
		else if (DP[i][j-1]>DP[i-1][j]) j--;
		else i--;
	}
	
	while (Q.size()) {
		cout<<Q.top()<<" "; Q.pop();
	}
	
	return 0;
}
