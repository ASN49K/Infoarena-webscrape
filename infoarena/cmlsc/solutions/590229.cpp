#include<cstdio>
using namespace std;

int dp[1025][1025];
int A[1025], B[1025];
int N, M;
int father[1025];

int max(int x, int y)
{
	if(x>y)
	return x;
	return y;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d", &N, &M);
	
	int i, j;
	for(i = 1; i <= N; i++)
	scanf("%d", &A[i]);
	for(j = 1; j <= M; j++)
	scanf("%d", &B[j]);
	
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= M; j++)
		{
			if(A[i] == B[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				
			}
			else
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	
	i = N; j = M;
	int temp = 0;
	int final[1025];
	
	while(i>0)
	{
		if (A[i] == B[j])
            final[++temp] = A[i], --i, --j;
        else if (dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
	}
	
	printf("%d\n",dp[N][M]);
	for(i = temp; i ; i--)
	printf("%d ", final[i]);
	printf("\n");
	return 0;
}
