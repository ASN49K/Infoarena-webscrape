#include <fstream>
#include <algorithm>

using namespace std;

int n,m;
int a[1025],b[1025];
int dp[1025][1025]={0};

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void reverseRecursiveWrite(int x, int y){
	if (x!=0 && y!=0)
	if (a[x]==b[y]) {
		reverseRecursiveWrite(x-1, y-1);
		out << a[x] << " ";
	}
	else{
		if (dp[x-1][y]>dp[x][y-1]) reverseRecursiveWrite(x-1, y);
		else reverseRecursiveWrite(x, y-1);
	}
}

int main(void){
		
	in >> n >> m;
	
	for (int i=1; i<=n; i++) in >> a[i];
	for (int i=1; i<=m; i++) in >> b[i];
	
	
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (a[i]==b[j]) dp[i][j] = dp[i-1][ j-1] + 1;
			else dp[i][j] = max(dp[i-1][ j], dp[i][ j-1]);
		}
	}
	
	out << dp[n][m] << "\n";
	
	reverseRecursiveWrite(n,m);
		
	in.close();
	out.close();
	return 0;
}
