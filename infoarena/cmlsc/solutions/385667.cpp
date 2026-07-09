#include<stdio.h>
#define N 1026

int n, m, i, j, u, sol[N][N], sir[N], a[N], b[N];

int max(int a, int b){
	if (a>b) return a;
	else	return b;
}

int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++) scanf("%d", &b[i]);
	
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j]) sol[i][j] = sol[i-1][j-1] + 1;
			else
				sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
	
	for (i=n, j=m; i>0 && j > 0; )
		if (sol[i][j] == sol[i-1][j-1] + 1 && sol[i-1][j] <= sol[i-1][j-1] && sol[i][j-1] <= sol[i-1][j-1])
			{sir[++u] = a[i]; i--; j--;}
		else
			if (sol[i-1][j] > sol[i][j-1]) i--;
			else	j--;
	
	printf("%d\n", sol[n][m]);
	for (i = u; i > 0; i--)
		printf("%d ",sir[i]);
	return 0;
}
