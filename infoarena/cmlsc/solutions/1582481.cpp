#include <iostream>
#include <fstream>

#define MAX 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m , n ,i , j ;
int M[MAX] , N[MAX] , a[MAX][MAX] , sol[MAX] , lg ;

int main()
{
    f >> n >> m;
    for ( i = 1; i <= n ; i++ ) f >> N[i];
    for ( j = 1; j <= m ; j++ ) f >> M[j];

    a[1][0] = a[0][1] = 1;

    for ( i = 1 ; i <= n ; i++ )
        for ( j = 1; j <= m ; j++ )
            if ( N[i] == M[j] )
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = max(a[i-1][j] , a[i][j-1]);

    for ( i = n , j = m ; i; )
    {
        if (N[i] == M[j])
            sol[++lg] = N[i] , --i , -- j;
        else if ( a[i-1][j] < a[i][j-1] ) --j;
                else --i;
    }
    g << lg << "\n";
    for ( i = lg ; i >=1 ; i--)
        g << sol[i] << " " ;

    return 0;
}
