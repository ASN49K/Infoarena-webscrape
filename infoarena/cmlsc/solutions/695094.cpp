#include<stdio.h>

long N, M, i, j, d[1200][1200], a[1200], b[1200], st[1200];

int main() {
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
		scanf("%ld %ld", &N, &M);
		
		for (i = 1; i <= N; ++i)
			scanf("%ld", &a[i]);

		for (j = 1; j <= M; ++j)
			scanf("%ld", &b[j]);
		
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j)
				(a[i] == b[j])?(d[i][j] = d[i-1][j-1] + 1):(d[i][j] = (d[i-1][j]<d[i][j-1])?d[i][j-1]:d[i-1][j]);
		
		for (i = N, j = M; i > 0;)
			(a[i] == b[j])?(st[++st[0]] = a[i],	--i, --j):((d[i-1][j] < d[i][j-1])?--j:--i);

		printf("%ld\n", st[0]);
		for (i = st[0]; i > 0; --i)
			printf("%ld ", st[i]);
		printf("\n");
	
	return 0;
}