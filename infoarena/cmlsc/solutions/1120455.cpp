//#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
int n, m;
char t[1025][1025];
int nb[2][1025];
int tt[1025];
int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);
	

	for (int i = 1; i <= n; ++i)
		scanf("%d", &nb[0][i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &nb[1][i]);

	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j){
		if (nb[0][i] == nb[1][j])
			t[i][j]=1+t[i-1][j-1];
		else
			t[i][j] += t[i - 1][j] > t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
	}/*
	for (int i = 1; i <= m; ++i)
		printf("%d ", nb[1][i]);
	printf("\n");
	for (int i = 1; i <= n; ++i){
		printf("%d ", nb[0][i]);
		for (int j = 1; j <= m; ++j)
			printf("%d ", t[i][j]);
		printf("\n");
	*/
	int l=0;
	while (t[n][m]){
		while (t[n][m] == t[n-1][m] )
			--n;
		tt[l] = nb[0][n];
		--n; --m; ++l;
	}
	printf("%d\n", l);
	for (int i = l-1; i >=0; --i)
		printf("%d ", tt[i]);
	return 0;
}