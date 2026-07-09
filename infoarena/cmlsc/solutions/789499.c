#include <stdio.h>

#define Nmax 1030
#define MAX(x,y) (x>y?x:y)

int A[Nmax],B[Nmax],D[Nmax][Nmax],S[Nmax],i,j,N,M,k,p,l;

int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&M,&N);
    for(i=1;i<=M;i++)
        scanf("%d",&A[i]);
    for(i=1;i<=N;i++)
        scanf("%d",&B[i]);

    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if(A[i]==B[j])
                D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=MAX(D[i-1][j],D[i][j-1]);

    l=0;
    i=M;j=N;
    k=D[i][j];
    while(k)
    {
        if(D[i][j]>D[i-1][j-1])
        {
            S[++l]=A[i--];
            j++;
        }

        else if(D[i-1][j]>=D[i][j-1])
                k=D[--i][j];
            else
                k=D[i][--j];
    }

    printf("%d\n",l);
    for(;l;--l)
        printf("%d ",S[l]);

    return 0;
}
