#include <iostream>
#include <fstream>
#define nmax 1025
using namespace std;

int a[nmax], b[nmax];
int pre[nmax];

int cmlsc(int i, int j) {
	if(i==0 || j==0) return 0;
	
	if(a[i] == b[j]) {
		pre[i] = i-1;
		return cmlsc(i-1, j-1) + 1;
	}

	return max(cmlsc(i,j-1), cmlsc(i-1,j));
}


int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	int n, m, i, j;
	
	f>>n>>m;
	for(i=1; i<=n; i++) f>>a[i];
	for(j=1; j<=m; j++) f>>b[j];
	
	g<<cmlsc(n, m)<<"\n";
	
	for(i=1; i<=n; i++) if(pre[i]) g<<a[i]<<" "; g<<"\n";
	
	return 0;
}

