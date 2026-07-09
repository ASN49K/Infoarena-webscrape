#include<cstdio>
#define maxim(a,b) a<b?b:a
using namespace std;

int A[1030],B[1030],LA,LB,R[1030][1030],i,j,k,S[1030],nr;

void read(),solve();

int main()
{
	read();
	solve();
	
	return 0;
}

void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&LA,&LB);
	for(i=1;i<=LA;i++)
		scanf("%d",&A[i]);
	for(i=1;i<=LB;i++)
		scanf("%d",&B[i]);
}

void solve()
{
	for(i=1;i<=LA;i++)
	{
		for(j=1;j<=LB;j++)
			if(A[i]==B[j])R[i][j]=R[i-1][j-1]+1;
		else
		{
			R[i][j]=maxim(R[i-1][j],R[i][j-1]);
		}
	}
	for(i=LA,j=LB;i&&j;)
	{
		if(A[i]==B[j])
		{
			S[++k]=A[i];i--;j--;
		}
		else if(R[i-1][j]<R[i][j-1]) j--;
			else i--;
	}
	printf("%d\n",k);
	for(;k;k--)
		printf("%d ",S[k]);
}
