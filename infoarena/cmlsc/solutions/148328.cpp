#include<stdio.h>
#define Nm 1026
#define max(a,b) ((a)>(b)?(a):(b))
int M[Nm][Nm],A[Nm],B[Nm],n,m;

void read()
{
	int i;

	freopen("cmlsc.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",A+i);
	for(i=1;i<=m;++i)
		scanf("%d",B+i);
}

void solve()
{
	int i,j;

	for(i=n;i;--i)
		for(j=m;j;--j)
			if(A[i]==B[j])
				M[i][j]=1+M[i+1][j+1];
			else
				M[i][j]=max(M[i+1][j],M[i][j+1]);
}

void write()
{
	int i=1,j=1;

	freopen("cmlsc.out","w",stdout);
	printf("%d\n",M[1][1]);
	while(M[i][j])
	{
		if(A[i]==B[j])
		{
			if(M[i][j]>1)
				printf("%d ",A[i]);
			else
				printf("%d\n",A[i]);
			++i; ++j;
		}
		else
			if(M[i+1][j]>M[i][j+1])
				++i;
			else
				++j;
	}
}

int main()
{
	read();
	solve();
	write();
	return 0;
}
