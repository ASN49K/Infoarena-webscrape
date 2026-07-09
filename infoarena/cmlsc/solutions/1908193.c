#include <stdio.h>

char dp[1025][1025];
char a[1025],b[1025];

int max(int a, int b){
	return (a>b)?a:b;
}

void printPath(int x, int y){
	
	int i = x, j = y;
	while ((i>0)&&(dp[i-1][j]==dp[i][j])) i--;
	while ((j>0)&&(dp[i][j-1]==dp[i][j])) j--;
	if (dp[i][j]>1) printPath(i-1, j-1);
	printf("%d ", a[i]);
	return;
}

int main(){
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	int m,n;
	
	
	scanf("%d %d", &m, &n);
	char i,j;
	for (i=1; i<=m; i++) scanf("%d", &a[i]);
	for (i=1; i<=n; i++) scanf("%d", &b[i]);

	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++){
			if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	printf("%d\n", dp[m][n]);
	printPath(m, n);
	return 0;
}
