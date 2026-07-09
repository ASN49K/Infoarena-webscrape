#include <fstream>
#define MAX 1025
using namespace std;

int dp[MAX][MAX];

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("cmlsc.in");
	fout.open("cmlsc.out"); 
	int m, n;
	int a[MAX], b[MAX];

	fin >> m >> n;
	for(int i=1; i <= m; ++i){
		fin >> a[i];
	}
	for(int i=1; i <= n; ++i){
		fin >> b[i];
	}

	for(int i=1; i <= m; ++i)
		for(int j=1; j <= n; ++j){

			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			
			if(a[i] == b[j])
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			
		}

	fout << dp[m][n] << "\n";
	for(int i=1; i <= m; ++i){
		if(dp[i][n] > dp[i - 1][n])
			fout << a[i] << " ";
	}


}