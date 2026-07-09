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
		t[i][j] += t[i - 1][j] > t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
		t[i][j]+=nb[0][i] == nb[1][j] ? 1 : 0;
	}
	/*for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j)
			printf("%d ", t[i][j]);
		printf("\n");
	}*/
	int i=n,j = m,in=t[n][m];
	while (t[i][j]){
		if (in != t[i][j]){
			tt[in] =nb[0][i];
			in--;
		}
		if (t[i][j] - 1 == t[i - 1][j])
			--i;
		else
		if (t[i][j] - 1 == t[i][j - 1])
			--j;
		else { --j; --i; }
	}
	printf("%d\n", t[n][m]-in);
	for (int i = 2; i <= t[n][m]; ++i)
		printf("%d ", tt[i]);
	return 0;
}