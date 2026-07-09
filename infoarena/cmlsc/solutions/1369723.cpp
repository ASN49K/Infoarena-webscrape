#include <fstream>
#include <algorithm>

using namespace std;

const int NMAX= 1024;

ifstream in( "cmlsc.in" );
ofstream out( "cmlsc.out" );

int A[NMAX+1], B[NMAX+1];
int D[NMAX+1][NMAX+1], ans[NMAX+1];

int main(  )
{
    int M, N;
    in >> M >> N;

    for( int i= 1; i<=M; ++i )
    {
        in >> A[i];
    }
    for( int i= 1; i<=N; ++i )
    {
        in >> B[i];
    }

    for( int i= 1; i<=M; ++i )
    {
        for( int j= 1; j<=N; ++j )
        {
            if( A[i] == B[j] )
            {
                D[i][j] = 1 + D[i-1][j-1];
            }
            else
            {
                D[i][j] = max( D[i-1][j], D[i][j-1] );
            }
        }
    }

    int sol = 0;

    for( int i= M, j= N ; i ; )
    {
        if( A[i] == B[j] )
        {
            ans[++sol] = A[i];
            --i;
            --j;
        }
        else if ( D[i-1][j] < D[i][j-1] )
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
