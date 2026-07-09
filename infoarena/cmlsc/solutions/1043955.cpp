#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

char a[1025],b[1025],v[1025];
short D[1025][1025];

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	int M,N;

	scanf("%d%d",&M,&N);
	for(int i=1;i<=M;++i) scanf("%d",&a[i]);
	for(int i=1;i<=N;++i) scanf("%d",&b[i]);

	memset(D,0,sizeof(D));

	for(int i=1;i<=M;++i)
		for(int j=1;j<=N;++j)
			if(a[i]==b[j]) D[i][j]=D[i-1][j-1]+1;
			else D[i][j]=max(D[i-1][j],D[i][j-1]);

	printf("%d\n",D[M][N]);

	int x=M,y=N;
	memset(v,0,sizeof(v));
	while(D[x][y]!=0)
	{
		while(D[x][y]==D[x-1][y]) --x;
		while(D[x][y]==D[x][y-1]) --y;

		v[D[x][y]]=a[x];
		--x;
		--y;
	}

	for(int i=1;i<=D[M][N];++i)
		printf("%d ",v[i]);
	printf("\n");

	return 0;
}

