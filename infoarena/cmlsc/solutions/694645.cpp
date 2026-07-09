#include <stdio.h>

int DP[1024][1024],A[1024],B[1024],v[1024];
int maxim(int a,int b){
	if (a>b)
		return a;
	return b;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i;

	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;++i)
		scanf("%d", &A[i]);
	for (int i=1;i<=m;++i)
		scanf("%d", &B[i]);
	DP[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (A[i]==B[j])
				DP[i][j]=DP[i-1][j-1]+1;
			else
				DP[i][j]=maxim(DP[i][j-1],DP[i-1][j]);
	}
	printf("%d\n", DP[n][m]);
	i=0;
	while (n && m){
		if (A[n]==B[m]){
			v[++i]=A[n];
			n--;
			m--;
		}
		else if (DP[n][m-1]>DP[n-1][m])
			m--;
		else 
			n--;
	}

	for (int j=i;j;--j)
		printf("%d ", v[j]);

	return 0;
}