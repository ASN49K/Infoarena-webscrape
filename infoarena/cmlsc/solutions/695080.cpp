#include<cstdio>

long N, M, i, j, d[1025][1025], a[1025], b[1025], st[1025];

int main() {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
		scanf("%ld %ld", &N, &M);
		
		for (i = 1; i <= N; ++i) {
			scanf("%ld", &a[i]);
		}
		
		for (j = 1; j <= M; ++j) {
			scanf("%ld", &b[j]);
		}
		
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= M; ++j) {
				if (a[i] == b[j]) {
					d[i][j] = d[i-1][j-1] + 1;
				} else {
					d[i][j] = (d[i-1][j]<d[i][j-1])?d[i][j-1]:d[i-1][j];
				}
			}
		}
		
		for (i = N, j = M; i > 0; ) {
			if (a[i] == b[j]) {
				st[++st[0]] = a[i],	--i, --j;
			} else {
				(d[i-1][j] < d[i][j-1])?--j:--i;
			}
		}
		printf("%ld\n", st[0]);
		for (i = st[0]; i > 0; --i) {
			printf("%ld ", st[i]);
		}
		printf("\n");
	
	return 0;
}