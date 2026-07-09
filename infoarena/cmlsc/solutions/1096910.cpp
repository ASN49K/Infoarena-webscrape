#include <cstdio>

using namespace std;

#define NMAX 1030

#define maxim(a,b) ((a>b)?(a):(b))

int N,M;

int A[NMAX],B[NMAX];
int DP[NMAX][NMAX];

void Read()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&A[i]);
    for(int i=1;i<=M;i++)
        scanf("%d",&B[i]);
}

void Solve()
{
    // DP[i][j] = lungimea celui mai lung subsir comun al sirurilor A[1...i] si B[1...j]

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            DP[i][j] = maxim(DP[i-1][j],DP[i][j-1]);
            if(A[i] == B[j])
                DP[i][j] = maxim(DP[i][j], DP[i-1][j-1] + 1);
        }
}

void Reconstruct(int i, int j)
{
    if(i<1 || j<1)
        return;

    if(A[i] == B[j])
    {
        Reconstruct(i-1,j-1);
        printf("%d ",A[i]);
    }
    else
        if(DP[i-1][j] > DP[i][j-1])
            Reconstruct(i-1,j);
        else
            Reconstruct(i,j-1);
}

void Print()
{
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",DP[N][M]);
    Reconstruct(N,M);
}

int main()
{
    Read();
    Solve();
    Print();
    return 0;
}
