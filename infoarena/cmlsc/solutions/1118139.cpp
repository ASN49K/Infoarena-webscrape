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
	int a=0, b=1;
	if (n > m){ a = 1; b = 0; }

	for (int i = 1; i <= n; ++i)
		scanf("%d", &nb[a][i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &nb[b][i]);

	if (n>m){ a = n; n = m; m = a; }
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j){
		t[i][j] += t[i - 1][j] > t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
		t[i][j]+=nb[0][i] == nb[1][j] ? 1 : 0;
	}
	
	int l = m,in=t[n][m];
	while (t[n][l]){
		while (t[n][l] == t[n][l - 1])--l;
		tt[in] = nb[1][l];
		--l; in--;
	}
	for (int i = 1; i <= t[n][m]; ++i)
		printf("%d ", tt[i]);
	return 0;
}