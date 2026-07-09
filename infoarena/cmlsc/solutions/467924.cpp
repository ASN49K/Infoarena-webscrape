#include<cstdio>
#include<algorithm>
void read(),solve(),afis(int M,int N);
int i,j,N,M,A[1025],B[1025],L[1025][1025];
using namespace std;
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
	scanf("%i%i",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%i",&A[i]);
	for(i=1;i<=N;i++)
		scanf("%i",&B[i]);
}
void solve()
{
	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(A[i]==B[j])
				L[i][j]=1+L[i-1][j-1];
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
	printf("%i\n",L[M][N]);
	afis(M,N);
}
void afis(int M,int N)
{
	if(L[M][N])
		if(A[M]==B[N])
		{
			afis(M-1,N-1);
			printf("%i ",A[M]);
		}
		else if(L[M][N]==L[M-1][N]) afis(M-1,N);
		else if(L[M][N]==L[M][N-1]) afis(M,N-1);
}

		