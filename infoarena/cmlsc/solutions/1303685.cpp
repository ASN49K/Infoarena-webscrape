#include <stdio.h>
#include <algorithm>

int main()
{
    int i,j,N,M;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&N,&M);
    int A[N],B[M],Tomb[N+1][M+1];
    for(i=0;i<N;++i)
        scanf("%d",&A[i]);
    for(i=0;i<M;++i)
        scanf("%d",&B[i]);
    for(i=0;i<=N;++i)
        Tomb[i][0]=0;
    for(i=0;i<=M;++i)
        Tomb[0][i]=0;
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            if(A[i-1]==B[j-1])
                Tomb[i][j]=Tomb[i-1][j-1]+1;
            else
                Tomb[i][j]=(Tomb[i-1][j]>Tomb[i][j-1] ? Tomb[i-1][j] : Tomb[i][j-1]);
    int szam=Tomb[N][M]-1,Sor[szam+1];
    for(i=N,j=M;i>0;)
        if(A[i-1]==B[j-1])
        {
            Sor[szam]=A[i-1];
            --szam;
            --j;
            --i;
        }
        else
        {
            if(Tomb[i][j-1]>Tomb[i-1][j])
                --j;
            else
                --i;
        }
    printf("%d\n",Tomb[N][M]);
    for(i=0;i<Tomb[N][M];++i)
        printf("%d ",Sor[i]);
}
