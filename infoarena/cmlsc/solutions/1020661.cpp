#include <cstdio>
#define Maxim(a,b) (a>b ? a:b)
using namespace std;

int X[1030][1030];
int N,M;
int A[1030],B[1030];
int Sol[1030];
int Nsol;


void Citire()
{
    scanf("%d %d\n",&N,&M);
    for(int i=1;i<=N;++i)
        scanf("%d ",&A[i]);
    for(int i=1;i<=M;++i)
        scanf("%d ",&B[i]);
}

void Rezolvare()
{
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            if(A[i]==B[j])
                X[i][j]=X[i-1][j-1]+1;
            else
                X[i][j]=Maxim(X[i-1][j],X[i][j-1]);
    for(int i=N,j=M;X[i][j]!=0;)
        if(A[i]==B[j])
        {
            Sol[Nsol++]=A[i];
            --i,--j;
        }
        else if(X[i-1][j]>X[i][j-1])
            --i;
        else
            --j;
}

void Afisare()
{
    printf("%d\n",X[N][M]);
    for(int i=Nsol-1;i>=0;--i)
        printf("%d ",Sol[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    Citire();
    Rezolvare();
    Afisare();
    return 0;
}
