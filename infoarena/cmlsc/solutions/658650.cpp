#include<cstdio>
#define max(a, b) (a > b ? a : b)

using namespace std;
int n, m;
int a[1025], b[1025], ab[1025][1025], sol[1025];

int main() {
	int i, j, k;
	
	freopen("cmlsc.in", "r", stdin), freopen("cmlsc.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(i = 1; i <= m; i++) scanf("%d", &b[i]);
	
	// initializare
	for(i = 0; i <= n; i++) ab[0][i] = 0;
	for(i = 0; i <= m; i++) ab[i][0] = 0;
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i] == b[j]) ab[i][j] = ab[i - 1][j - 1] + 1;
			else ab[i][j] = max(ab[i - 1][j], ab[i][j - 1]);
	
	i = n, j = m, k = ab[n][m];	
	while(k > 0) {
		if(a[i] == b[j]) sol[k--] = a[i], i--, j--;
		else if(ab[i - 1][j] > ab[i][j - 1]) i--;
		else j--;
	}
	
	printf("%d\n", ab[n][m]);
	for(i = 1; i <= ab[n][m]; i++) printf("%d ", sol[i]);
	
	return 0;
}
