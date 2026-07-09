#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n1[1030];
int n2[1030];
int dp[1024][1024];
int n, m;

void Citire(){
	fin>>m>>n;
	for(int i=1; i<=m; i++){
		fin>>n1[i];
	}
	for(int i=1; i<=n; i++){
		fin>>n2[i];
	}
}

int main(int argc, char** argv) {
	
	
	Citire();
	//zerografiere
	
	for(int i=0; i<=m; i++){
		dp[i][0]=0;
	}
	for(int j=0; j<=n; j++){
		dp[0][j]=0;
	}
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(n1[i]==n2[j]) dp[i][j]= 1 + dp[i-1][j-1]; 
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int lastI = 0;
	int result[1025];
	for(int i=0; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(dp[i][j]>lastI){
				result[lastI] = n2[j];
				lastI++;
			}
		}
	}
	fout<<dp[m][n]<<endl;
	for(int i=0; i<lastI; i++){
		fout<<result[i]<<" ";
	}
	return 0; 
}
