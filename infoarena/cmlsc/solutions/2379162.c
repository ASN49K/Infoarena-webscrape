#include<stdio.h>

int main(){
	int m, n, i, j, k;
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
	k = c[m][n];
	int v[k];
	printf("%d\n", k);
	i = m; j = n;
	while(k != 0){
		if(c[i][j] == c[i-1][j])
			i--;
		if(c[i][j] == c[i][j-1])
			j--;
		if(c[i][j] != c[i-1][j] && c[i][j] != c[i][j-1]){
			v[k - 1] = a[i-1];
			k--;
			i--;
			j--;
		}
	}
	for(i = 0; i < c[m][n]; i++)
		printf("%d ", v[i]);
	return 0;
}
