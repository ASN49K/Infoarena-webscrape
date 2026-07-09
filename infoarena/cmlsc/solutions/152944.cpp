#include<stdio.h>
#include<algorithm>

using namespace std;

#define lg 102

int n, m, i, j, v1[lg], v2[lg], d[lg][lg], nr[lg];

int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i ++)
		scanf("%d", &v1[i]);
	for (i = 1; i <= m; i ++)
		scanf("%d", &v2[i]);
	
	for (i = 1; i <= n; i ++)
		for (j = 1; j <= m; j ++)
			if (v1[i] == v2[j])
				d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = max(d[i-1][j], d[i][j-1]);

	printf("%d\n", d[n][m]);

	for (i = n, j = m; i; )
		if (v1[i] == v2[j]){
			nr[++nr[0]] = v1[i];

			i --, j --;
		}
		else
			if (d[i-1][j] >= d[i][j-1])
				i --;
			else
				j --;

	for (i = nr[0]; i; i --)
		printf("%d ", nr[i]);
	printf("\n");

	return 0;
}

