#include<iostream>
#include<fstream>
#define NMAX	1024
#define max(a,b) (a>b? a:b)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[NMAX], B[NMAX], C[NMAX][NMAX], subsir[NMAX],k=0;
int i,j, m, n;

int main() {

	fin>>n>>m;
	
	for(i=1; i<=n; i++){	fin>>A[i];}
	for(i=1; i<=m; i++){	fin>>B[i];}
	
	for(i=1; i<=n; i++){
	for(j=1; j<=m; j++){
		if(A[i]==B[j])
			C[i][j] = C[i-1][j-1] +1;
		else
			C[i][j]	= max(C[i][j-1], C[i-1][j]);
	}}	
	j = m; 
	i = n;
	while(i && j){
		if(A[i]==B[j]){
			subsir[++k] = A[i];
			i--;	j--;
		}else {
			if(C[i-1][j]> C[i][j-1])		
				i--;			
			else
				j--;
		}
	}
	fout<<k<<'\n';	
	for(i=k; i>1; i--) {fout<<subsir[i]<<" ";}

	fin.close();
	fout.close();
return 0;
}
