#include<stdio.h>
int v[1050],u[1050],dp[1050][1050],N,M;
int next[1050],k=0;
int maxim(int x,int y)
{
	if(x>y) return x;
	return y;
}
void citire()
{
	int i;
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&u[i]);
}
void dinamica()
{
	for(int i=1;i<=M;i++)
		for(int j=1;j<=N;j++)
			if(v[i]==u[j])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=maxim(dp[i-1][j],dp[i][j-1]);
	printf("%d ",dp[M][N]);
}
void construire(int i,int j)
{
	while(i>0&&j>0)
	{
		if(v[i]==u[j])
		{
			next[k++]=v[i];
			construire(i-1,j-1);break;
		}
		else
			if(dp[i-1][j]>dp[i][j-1])
			{
				 construire(i-1,j);break;
			}
			else
			{
				construire(i,j-1);break;
			}
	}
}
void afisare(int s)
{
	if(s>=0)
	{
		printf("%d ",next[s]);
		afisare(s-1);
	}
}
int main()
{
	int s;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	citire();
	dinamica();
	construire(M,N);
	s=k-1;printf("\n");
	afisare(s);
	return 0;
}