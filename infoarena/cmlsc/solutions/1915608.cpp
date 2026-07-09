#include <fstream>
#include <stack>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

stack <int> st;

int i, j, n, m, a[1025] , b[1025] , dp [1025][1025], ma, nr ;


int main ()
{
    f>>n>>m;

    for ( i = 1; i <= n; i++ )
    {
        f>>a[i];
    }

    for ( i = 1; i <= m; i++ )
    {
        f>>b[i];
    }

    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1; j <= m; j ++ )
        {
            if ( b[j] == a[i] )
            {
                dp[ i ][ j ] = 1 + dp [ i - 1 ][ j - 1 ];
            }
            else
            {
                dp[ i ][ j ] =  max ( dp [ i  ][ j - 1 ], dp [ i ][ j - 1 ] );
            }
        }
    }



    i=n;
    j=m;

    while ( i > 1 || j > 1 )
    {
        if ( dp [ i ][ j ] == dp [ i ][ j -1 ] )
        {
            j--;
        }
        else if ( dp[ i ][ j ] == dp [ i - 1 ] [ j ] )
        {
            i--;
        }
        else
        {
            nr++;
            st.push( a[i] );
            i--;
            j--;
        }
    }

    g<<nr<<'\n';

    if ( dp[1][1] ==  1 )
        st.push(a[i]);
    while ( !st.empty() )
    {
        g<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
