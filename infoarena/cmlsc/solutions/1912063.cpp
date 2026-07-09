#include <fstream>
using namespace std;

char dp[1025][1025];
char a[1025],b[1025];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max(int a, int b){
	return (a>b)?a:b;
}

void printPath(int x, int y){
	
	int i = x, j = y;
	while ((i>0)&&(dp[i-1][j]==dp[i][j])) i--;
	while ((j>0)&&(dp[i][j-1]==dp[i][j])) j--;
	if (dp[i][j]>1) printPath(i-1, j-1);
	fout << a[i] << " ";
	return;
}

int main(){
	
	int m,n;
	
	
	fin >> m >> n;
	char i,j;
	for (i=1; i<=m; i++) fin >> a[i];
	for (i=1; i<=n; i++) fin >> b[i];

	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++){
			if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	fout << dp[m][n] << "\n";
	printPath(m, n);
	return 0;
}
