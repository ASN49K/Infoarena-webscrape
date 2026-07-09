#include<stdio.h>

int main(){
	int m, n, i, j, k = 1;
	int a[1025], b[1025];
	freopen("cmlsc.in", "r", stdin);   
    	freopen("cmlsc.out", "w", stdout);   
	scanf("%d%d", &m, &n);
	int c[m + 1][n + 1];
	for(i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for(i = 0; i <= m; i++)
		for(j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				c[i][j] = 0;
			else if(a[i - 1] == b[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = c[i - 1][j] < c[i][j - 1] ? c[i][j-1] : c[i-1][j];
		}
	printf("%d\n", c[m][n]);
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(c[i][j] - c[i-1][j] == 1 && k == c[i][j]){
				k++;
				printf("%d ", a[i - 1]);
			}
		}
	}
	return 0;
}
