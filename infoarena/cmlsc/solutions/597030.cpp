#include <cstdio>

const int NMAX = 1<<10;

int A[NMAX ] , B[NMAX] , D[NMAX][NMAX] , S[NMAX] , n , m , dmax;

static inline int max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;++i)   scanf("%d",&A[i]);
	for(int i=1;i<=n;++i) 	scanf("%d",&B[i]);

	for(int i=1;i<=m;++i)  
		for(int j=1;j<=n;++j) 
			if(A[i]==B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = max(D[i-1][j],D[i][j-1]);
	for(int i=m , j=n; i;)
		if(A[i]==B[j])
			S[++dmax] = A[i] , --i , --j;
		else
			if(D[i-1][j] < D[i][j-1])
				--j;
			else
				--i;
	printf("%d\n",dmax);
	for(int i=dmax;i;--i)
		printf("%d ",S[i]);
	return 0;
}