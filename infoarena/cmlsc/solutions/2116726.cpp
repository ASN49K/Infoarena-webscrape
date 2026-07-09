#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[2000],B[2000],m,n,C[2000][2000],P[2000][2000];

int scrie(int i, int j){
	if(i==0 || j==0)
		return 0;
		if(P[i][j]==1){
			scrie(i-1,j-1);
			fout<<A[i]<<" ";
		}
		else
			if(P[i][j]==2)
				scrie(i-1,j);
			else
				scrie(i,j-1);
}

int main(){
	
	fin>>m>>n;
	for(int i=1;i<=m;i++)
		fin>>A[i];
	for(int i=1;i<=n;i++)
		fin>>B[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(A[i]==B[j]){
				C[i][j]=C[i-1][j-1]+1;
				P[i][j]=1;
			}
			else
				if(C[i-1][j]>=C[i][j-1]){
					C[i][j]=C[i-1][j];
					P[i][j]=2;
				}
				else{
					C[i][j]=C[i][j-1];
					P[i][j]=3;
				}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++)
//			fout<<P[i][j]<<" ";
//		fout<<"\n";
//	}
	fout<<C[m][n]<<"\n";
	scrie(m,n);
	
	
	
	return 0;
}

