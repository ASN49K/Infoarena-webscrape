#include <stdio.h>
#include <string.h>

int i,j,N,M,x,y,L;
int A[1025],B[1025],sol[1025],D[1025][1025];

inline int fmax(int a,int b)
{
	if(a<b) return b;
	else return a;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++) scanf("%d",&A[i]);
	for(i=1;i<=N;i++) scanf("%d",&B[i]);

	memset(D,0,sizeof(D));

	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
			if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
			else D[i][j]=fmax(D[i-1][j],D[i][j-1]);

	printf("%d\n",D[M][N]);
	x=M;
	y=N;
	L=D[M][N];

	memset(sol,0,sizeof(sol));

	while(L>0)
	{
		while(D[x-1][y]==L) x--;
		while(D[x][y-1]==L) y--;
		sol[++sol[0]]=A[x];
		L--;
		x--;
		y--;
	}

	for(i=sol[0];i>1;i--)
		printf("%d ",sol[i]);

	printf("%d\n",sol[1]);

	return 0;
}
