#include <cstdio>
#define DIM 1050
using namespace std;

int v[DIM], d[DIM], sol[DIM];
int best[DIM][DIM];

int maxim( int a, int b ){
    if( a > b ) return a;
    else return b;
}

int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    int n, m, i, j, s, t, k;

    scanf("%d%d",&n,&m);
    for( i = 1; i <= n; ++i ) scanf("%d",&v[i]);
    for( i = 1; i <= m; ++i ) scanf("%d",&d[i]);

    for( i = 1; i <= n; ++i ){
        for( j = 1; j <= m; ++j ){
            if( v[i] == d[j] ) best[i][j] = best[i-1][j-1] + 1;
            else best[i][j] = maxim( best[i-1][j], best[i][j-1] );
        }
    }
    printf("%d\n",best[n][m]);


    s = 0;
    while( n && m ){
        if( v[n] == d[m] ){
            sol[++s] = v[n];
            n--, m--;
        }
        else if( best[n][m-1] > best[n-1][m] ) m--;
        else n--;
    }

    for( i = s; i >= 1; --i ){
        printf("%d ",sol[i]);
    }


    return 0;
}
