#include <bits/stdc++.h>
using namespace std;
ifstream fin("mmm.in");
ofstream fout("mmm.out");
int n,m,A[1050],B[1050],C[1050][1050],p[1050],rs;
int main(){
	fin>>n>>m;
	for(int i=1; i<=n; i++) fin>>A[i];
	for(int i=1; i<=m; i++) fin>>B[i];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) if(A[i]==B[j]) {
			C[i][j]=C[i-1][j-1]+1;
		} else C[i][j]=max(C[i-1][j], C[i][j-1]);
	}
    int i=n, j=m;
    rs=0;
    while(i){
    	if(A[i]==B[j]){
    		p[++rs]=A[i];
    		i--;j--;
		}else if(C[i-1][j]<C[i][j-1]) j--; else i--;
	}
    fout<<C[n][m]<<'\n';
    for(int i=rs; i>=1; i--) fout<<p[i]<<' ';
}
