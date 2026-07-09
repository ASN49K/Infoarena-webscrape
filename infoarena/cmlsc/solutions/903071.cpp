#include <cstdio>
#define max(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1026

int M, N, A[NMax], B[NMax], DP[NMax][NMax], sir[NMax], bst;

void dynamics ( void )
{
	int i,j;
	FOR(i, 1, N) 
	 FOR(j, 1, M)
	   if(A[i] == B[j] )
		   DP[i][j]= 1 + DP[i-1][j-1];
	   else
		   DP[i][j]=max(DP[i-1][j],DP[i][j-1]);	
}

void solve ( void )
{
	int i,j;
	for(i=N,j=M; i;)
		if(A[i] == B[j] ) 
			sir[++bst]=A[i],--i,--j;
		else
			if( DP[i-1][j] < DP[i][j-1] ) --j;
		else --i;
	
}
void write (  void )
{    int i;
	printf("%d\n",bst);
	for( i=bst; i;i-- )
		printf("%d ", sir[i]);
}


int main( void )
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &N, &M);
    FOR (i, 1, N)  scanf("%d", &A[i]);
    FOR (i, 1, M)  scanf("%d", &B[i]);
	
	dynamics();
	solve();
	write();
	return 0;
}	