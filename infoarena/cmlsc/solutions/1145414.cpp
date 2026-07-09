/*
    Keep It Simple!
*/

#include<stdio.h>
#include<list>

using namespace std;

#define MaxN 1025

int Dp[MaxN][MaxN],N,M,FirstString[MaxN],SecondString[MaxN];

list<int> LCS;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&N,&M);

	for(int i=1; i<=N; i++)
		scanf("%d",&FirstString[i]);
	for(int j=1; j<=M; j++)
		scanf("%d",&SecondString[j]);

	// Compute LCS value

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
		{
			if( FirstString[i] == SecondString[j] )
			   Dp[i][j] = Dp[i-1][j-1] + 1;
			else
			   Dp[i][j] = max(Dp[i-1][j],Dp[i][j-1]);
		}

	printf("%d\n",Dp[N][M]);

	// Compute LCS
	int i = N, j = M;

	while( i && j )
	{
		if( FirstString[i] == SecondString[j] )
		{
			LCS.push_front(FirstString[i]);
			--i;--j;
		}
		else if( Dp[i-1][j] > Dp[i][j-1] )
		   --i;
		   else --j;
	}

	for(list<int>::iterator it = LCS.begin(); it!=LCS.end(); it++)
		printf("%d ",*it);

}
