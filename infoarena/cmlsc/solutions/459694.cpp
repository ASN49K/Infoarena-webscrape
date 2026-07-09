#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1031

/*
 *
 */
 int v[Nmax], w[Nmax];
 int cmlsc[Nmax][Nmax];
 std::vector< int > r;
 int main( void )
 {
     int N, M, i, j;
     std::ifstream in( "cmlsc.in" );
     in>>N>>M;
     for( i=1; i <= N; ++i )
        in>>v[i];
     for( i=1; i <= M; ++i )
        in>>w[i];
     for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( v[i] == w[j] )
                cmlsc[i][j]=1+cmlsc[i-1][j-1];
            else cmlsc[i][j]=( cmlsc[i-1][j] >= cmlsc[i][j-1] ? cmlsc[i-1][j] : cmlsc[i][j-1] );
     std::ofstream out( "cmlsc.out" );
     out<<cmlsc[N][M]<<'\n';
     for( i=N, j=M; i && j; )
        if( v[i] == w[j] )
            r.push_back(v[i]), --i, --j;
        else if( cmlsc[i-1][j] >= cmlsc[i][j-1] )
                --i;
             else --j;
     std::copy( r.rbegin(), r.rend(), std::ostream_iterator<int>( out, " " ) );
     out<<'\n';
     return EXIT_SUCCESS;
 }
