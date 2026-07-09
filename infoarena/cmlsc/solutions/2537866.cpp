#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short n1[1030];
short n2[1030];
int dp[1024][1024];
int n, m;

int main(int argc, char** argv) {
	
	fin>>m>>n;
	for(int i=1; i<=m; i++){
		fin>>n1[i];
	}
	for(int i=1; i<=n; i++){
		fin>>n2[i];
	}
	
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
	short result[1025];
	int i = m, j = n;
	while(i && j){
		 if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1]){
            result[lastI] = n1[i];
            lastI++;
            i--;
            j--;
        }else if(dp[i-1][j]==dp[i][j]){
            i--;
        }else{
            j--;
        }
	}
	fout<<dp[m][n]<<endl;
	for(int i=lastI-1; i>=0; i--){
		fout<<result[i]<<" ";
	}
	return 0; 
}
