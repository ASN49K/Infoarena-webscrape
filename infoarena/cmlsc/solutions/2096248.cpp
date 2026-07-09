#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[1100], b[1100];
int DP[1100][1100],s[1100];

int main() {
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	
	cin>>n>>m;
	
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int j=1; j<=m; j++) cin>>b[j];
	
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i]==b[j]) {
				DP[i][j]=DP[i-1][j-1]+1; 
			} else {
				DP[i][j]=max(DP[i][j-1], DP[i-1][j]);
			}
		}
	}/*cout<<'\n';
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) cout<<DP[i][j]; cout<<'\n';
	}*/
	int k=0;
	for (int i=n, j=m; i;) {
		if (a[i]==b[j]) s[++k]=a[i], --i, --j;
		else if (DP[i-1][j]>DP[i][j-1]) i--;
		else j--;
	}
	cout<<DP[n][m]<<'\n';

	for (int i=1; i<=DP[n][m]; i++) cout<<s[DP[n][m] - i +1]<<" ";
	
	
	return 0;
}
