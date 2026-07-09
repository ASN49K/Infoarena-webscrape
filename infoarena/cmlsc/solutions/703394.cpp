#include <cstdio>
#include <algorithm>

using namespace std;

#define maxN 1030

int N , M , sol[maxN] , dp[maxN][maxN] , A[maxN] , B[maxN];

int main ()
{
	freopen ("cmlsc.in" , "r" , stdin);
	freopen ("cmlsc.out" , "w" , stdout);
	
	scanf ("%d %d" , &N , &M);
	
	for (int i = 1 ; i <= N ; ++i)
		scanf ("%d" , &A[i]);
	
	for (int i = 1 ; i <= M ; ++i)
		scanf ("%d" , &B[i]);
	
	
	for (int i = 1 ; i <= N ; ++i)
		for (int j = 1 ; j <= M ; ++j)
			if (A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			
			else dp[i][j] = max (dp[i - 1][j] , dp[i][j - 1]);
	
	
	printf ("%d\n" , dp[N][M]);
	
	int dim = 0;
	
	for (int i = N , j = M ; i && j ;)
		if (A[i] == B[j])
		{
			sol[++dim] = A[i];
			
			--i , --j;
		}
		
		else if (dp[i - 1][j] > dp[i][j - 1])
			--i;
		
		else --j;
	
	
	for (int i = dim ; i >= 1 ; --i)
		printf ("%d " , sol[i]);
	
	return 0;
}
