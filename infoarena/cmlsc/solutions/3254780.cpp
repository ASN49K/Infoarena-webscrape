#include <stdio.h>

const int nmax = 1024;
int M,N,A[nmax],B[nmax],D[nmax][nmax],sir[nmax],bst;

int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&M,&N);
    for (i=1;i<=M;++i)
    {
        scanf("%d",&A[i]);
    }
    for (i=1;i<=N;++i)
    {
        scanf("%d",&B[i]);
    }
    for (i=1;i<=M;++i)
    {
        for (j=1;j<=N;++j)
        {
            if (A[i]==B[j])
            {
                D[i][j]=1+D[i-1][j-1];
            }
            else
            {
                D[i][j]=(D[i-1][j]>D[i][j-1])?D[i-1][j]:D[i][j-1];
            }
        }
    }
    i=M;
    j=N;
    while(i>0&&j>0)
    {
        if(A[i]==B[j])
        {
            sir[++bst]=A[i];
            --i;
            --j;
        }
        else if(D[i-1][j]>=D[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    printf("%d\n",bst);
    for(i=bst;i>0;--i)
    {
        printf("%d",sir[i]);
    }
    return 0;
}
