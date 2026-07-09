#include <fstream>
#include <algorithm>

using namespace std;

const int NMAX= 1024;

ifstream in( "cmlsc.in" );
ofstream out( "cmlsc.out" );

int A[NMAX+1], B[NMAX+1];
int d[NMAX+1][NMAX+1], ans[NMAX+1];
int sol;

int main(  )
{
    int N, M;
    in >> N >> M;

    for( int i= 1; i<=N; ++i )
    {
        in >> A[i];
    }
    for( int i= 1; i<=M; ++i )
    {
        in >> B[i];
    }

    for( int i= 1; i<=N; ++i )
    {
        for( int j= 1; j<=M; ++j )
        {
            if( A[i] == B[j] )
            {
                d[i][j] = 1 + d[i-1][j-1];
            }
            else
            {
                d[i][j] = max( d[i-1][j], d[i][j-1] );
            }
        }
    }

    for( int i= N, j= M ; i ; )
    {
        if( A[i] == B[j] )
        {
            ans[++sol] = A[i];
            --i;
            --j;
        }
        else if ( d[i-1][j] < d[i][j-1] )
        {
            --j;
        }
        else
        {
            --i;
        }
    }

    out << sol << '\n';

    for( int i = sol; i>=1; --i )
    {
        out << ans[i] << ' ';
    }

    return 0;
}
