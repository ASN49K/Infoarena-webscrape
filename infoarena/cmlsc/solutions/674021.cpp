#include<cstdio>
using namespace std;

const char in[]="cmlsc.in";
const char out[]="cmlsc.out";

const int N = 1050;

int A[N], B[N], C[N][N], n, m, S[N], bst;

inline int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

int main()
	{
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		
		scanf("%d %d", &n, &m);
		
		for(int i = 1 ; i <= n ; ++i)
			scanf("%d", &A[i]);
		
		for(int i = 1 ; i <= m ; ++i)
			scanf("%d", &B[i]);
		
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= m ; ++j)
				if(A[i] == B[j])
					C[i][j] = C[i - 1][j - 1] + 1;
				else C[i][j] = max(C[i - 1][j], C[i][j - 1]);
				
		for(int i = n, j = m; i ; )
				if(A[i] == B[j])S[++bst] = A[i], --i, --j;
				else if(C[i][j - 1] > C[i - 1][j]) --j;
				else --i;
		printf("%d\n",bst);
				
		for( ;bst ; )
			printf("%d ", S[bst--]);
		
		return 0;
}
			
			
			
				
				
			
			
			
			
			
			
				
		
		
		
		
