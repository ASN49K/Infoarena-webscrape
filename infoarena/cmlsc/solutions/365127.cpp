#include<cstdio>

#define MAXN ( 1 << 10 ) + 10

int A[MAXN][MAXN] , i , j , k , best[MAXN] , n , m ;
int x[MAXN] , y[MAXN];

inline int max ( int a , int b ) {
	if ( a > b ) return a;
return b;
}

int main ()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	for( i = 1 ; i <= n ; ++i )
		scanf("%d",&x[i]);
	
	for( i = 1 ; i <= m ; ++i )
		scanf("%d",&y[i]);
	
	
	for( i = 1 ; i <= n ; ++i )
			for( j = 1 ; j <= m ; ++j )
				if ( x[i] == y[j] ) 
						A[i][j] = A[i - 1][j - 1] + 1;
				else
						A[i][j] = max ( A[i - 1][j] , A[i][j - 1]);
				
	for( i = n , j = m ; i && j ; ) {
		if ( x[i] == y[j] ) best[++k] = x[i] , --i , --j;
			else
				if ( A[i - 1][j] > A[i][j - 1] ) 
					--i;
				else
					--j;
	}
	
		printf("%d\n",A[n][m]);
		
		for( i = k ; i >= 1 ; --i )
			printf("%d ",best[i]);
return 0;
}