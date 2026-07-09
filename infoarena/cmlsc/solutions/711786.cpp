#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in"); ofstream g("cmlsc.out");

int a[1030], b[1030], dp[1030][1030];
int i, j, n, m;

void afisare (int fi, int fj) {
	while (dp[fi-1][fj]==dp[fi][fj]) fi--;
	while (dp[fi][fj-1]==dp[fi][fj]) fj--;
	if (dp[fi][fj]!=1) afisare (fi-1, fj-1);
	g<<a[fi]<<" ";
}

int main(){
	f>>n>>m;
	for (i=1; i<=n; i++) f>>a[i];
	for (i=1; i<=m; i++) f>>b[i];
	
	for (i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			if (a[i]==b[j])	dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	g<<dp[n][m]<<"\n";
	
	afisare (n, m);
}