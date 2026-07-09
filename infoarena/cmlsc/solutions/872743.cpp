#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 1025

int n, m ;
int a[maxn], b[maxn] ;

int sol[maxn][maxn] ;

int sir[maxn] ;

int main()
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; ++i )
        scanf("%d", &a[i]);

    for(int i = 1; i <= m; ++i )
        scanf("%d", &b[i]);

    for(int i = 1; i <= n; ++i )
    {
        for(int j = 1; j <= m; ++j )
        {
            if( a[i] == b[j] )
                sol[i][j] = sol[i-1][j-1] + 1 ;
            else
                sol[i][j] = max( sol[i][j-1], sol[i-1][j] ) ;
        }
    }

    printf("%d\n", sol[n][m]);

    int ind1 = n ;
    int ind2 = m ;

    int nr = 0 ;

    while( sol[ind1][ind2] )
    {
        while( sol[ind1][ind2] == sol[ind1-1][ind2] )
            --ind1 ;

        while( sol[ind1][ind2] == sol[ind1][ind2-1] )
            --ind2 ;

        sir[++nr] = a[ind1] ;

        --ind1 ;
        --ind2 ;

    }

    for(int i = nr; i >= 1; --i )
        printf("%d ", sir[i]);

    printf("\n");

    return 0;

}
