#include <stdio.h>
#define max(x, y) x>y?x:y
 
int mat[1030][1030];
int a[1030], b[1030], v[1030];
int n, m;

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
		}
	}
	int lc = n, cc = m;
	int rez = mat[lc][cc];
	printf("%d\n", rez);
	int lv = 0;
	while(lc > 0 && cc > 0)
	{
		while(mat[lc][cc] == mat[lc - 1][cc] && lc != 1)
			lc--;
		while(mat[lc][cc] == mat[lc][cc - 1] && cc != 1)
			cc--;
		if(mat[lc][cc] == mat[lc - 1][cc - 1] + 1 && mat[lc - 1][cc] != mat[lc][cc] && mat[lc][cc - 1] != mat[lc][cc])
		{
			v[lv++] = a[lc];
			lc--; cc--;
		}
	}
	for(int i = lv - 1; i >= 0; i--)
		printf("%d ", v[i]);
}