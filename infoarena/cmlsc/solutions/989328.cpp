#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a) ; i >= (b) ; --i)
#define Nmax 1030
using namespace std;

int N,M,A[ Nmax ],B[ Nmax ],D[ Nmax ][ Nmax ],sir[ Nmax ],nre;

void solve()
{
    FOR(i,1,N)
        FOR(j,1,M)
            if(A[ i ] == B[ j ])
                D[ i ][ j ] = D[ i - 1 ][ j - 1 ] + 1;
            else
                D[ i ][ j ] = max ( D[ i - 1 ][ j ],D[ i ][ j - 1 ]);
}

void reconstituie()
{
    int i = N , j = M;
    while ( i )
    {
        if(A[ i ] == B[ j ])
        {
            sir[ ++nre ] = A[ i ];
            --i,--j;
        }
        else
            D[ i - 1 ][ j ] < D[ i ][ j - 1 ] ? --j : --i ;
    }

}

void PRINT ()
{
    printf("%d\n",nre);
    while(nre)
        printf("%d ",sir[nre--]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&N,&M);

    FOR(i,1,N)
        scanf("%d",&A[ i ]);
    FOR(i,1,M)
        scanf("%d",&B[ i ]);

    solve();
    reconstituie();
    PRINT();
    return 0;
}
