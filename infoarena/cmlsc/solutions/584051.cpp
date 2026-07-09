#include<fstream>
#include<cstdio>
#define maxim(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int MaxN = 1025;
const char InFile[] = "cmlsc.in";
const char OutFile[] = "cmlsc.out";

int N,M,X[MaxN],Y[MaxN],dp[MaxN][MaxN],sol[MaxN];

void cmlsc()
{
	int i,j;
	for( i = 1 ; i <= N ; i++ )
		for( j = 1 ; j <= M ; j++ )
			if( X[i] == Y[j] )
				dp[i][j] = dp[i-1][j-1]+1;
				else
				dp[i][j] = maxim(dp[i-1][j],dp[i][j-1]);
	i = N; j = M;
	while( i && j )
		if( X[i] == Y[j] )
			{
				sol[++sol[0]] = X[i];
				--i;
				--j;
			}
			else
			if( dp[i-1][j] > dp[i][j-1] )
				--i;
				else
				--j;
}

int main()
{
	freopen( InFile , "r" , stdin );
	freopen( OutFile , "w" , stdout ); 
	scanf("%d%d" , &N , &M);
	int i;
	for( i = 1 ; i <= N ; i++ )
		scanf("%d" , X+i );
	for( i = 1 ; i <= M ; i++ )
		scanf("%d" , Y+i );
	cmlsc();
	printf("%d\n" , sol[0]);
	for( i = sol[0] ; i ; --i )
		printf("%d " , sol[i]);
	printf("\n");
	return 0;
}
