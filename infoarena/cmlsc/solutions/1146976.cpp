#include<cstdio>
using namespace std;
int i,j,n,m,nr,a[1001],b[1001],d[1001][1001],s[1001];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
            else
            {
                if(d[i-1][j]>d[i][j-1])d[i][j]=d[i-1][j];
                else d[i][j]=d[i][j-1];
            }
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            nr++;
            s[nr]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])j--;
            else i--;
    }
    printf("%d\n",nr);
    for(i=nr;i>=1;i--)
        printf("%d ",s[i]);
    printf("\n");
    return 0;
}
/*#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    FOR (i, 1, M)
        scanf("%d", &A[i]);
    FOR (i, 1, N)
        scanf("%d", &B[i]);

    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}*/
