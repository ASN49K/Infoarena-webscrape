#include <cstdio>
#define N 1024

int C[N][N],A[N],B[N],rez[N],n,m,i,j;

inline int max(int a, int b)
{
    return (a>b?a:b);
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d\n",&m,&n);
	for (i=1; i<=m; i++) scanf("%d",&A[i]);
	for (i=1; i<=n; i++) scanf("%d",&B[i]);

    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (A[i]==B[j]) C[i][j]=C[i-1][j-1]+1;
            else            C[i][j]=max(C[i][j-1],C[i-1][j]);
    printf("%d\n",C[m][n]);

    i=m; j=n;
    int k=0;
    while (i && j)
    {
        if (A[i]==B[j])
        {
            rez[++k]=A[i];
            i--; j--;
        }
        else
            if (C[i-1][j]>C[i][j-1]) i--;
            else                     j--;
    }
    for (i=k; i; i--) printf("%d ",rez[i]);

    return 0;
}
