#include<bits/stdc++.h>
#define NMAX 1030

using namespace std;

int n,m,a[NMAX],b[NMAX];
int L[NMAX][NMAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void rec(int i, int j) {
	if (i==0 || j==0) return;
	if (a[i]==b[j]) {
		rec(i-1, j-1);
		fout<<a[i]<<" ";
	} else {
		if (L[i-1][j]>L[i][j-1]) rec(i-1, j);
		else rec(i, j-1);
	}
}

int main() {
	fin>>n>>m;
	
	for (int i=1; i<=n; i++) fin>>a[i];
	for (int i=1; i<=m; i++) fin>>b[i];
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i]==b[j]) L[i][j] = L[i-1][j-1] + 1;
			else L[i][j]=max(L[i][j-1],L[i-1][j]);
		}
	}

	fout<<L[n][m]<<'\n';
	
	rec(n,m);

	return 0;
}

