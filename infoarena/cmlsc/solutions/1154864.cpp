#include<fstream>
#include<vector>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

const int nmax = 1024;
short int x[ nmax + 1 ], y[ nmax + 1 ];
vector <short int> d[ nmax + 1 ][ nmax + 1 ];

int main()
{
    int n, m;
    fin>>n>>m;
    for( int i = 1; i <= n; ++ i ) {
        fin>>x[i];
    }
    for( int i = 1; i <= m; ++ i ) {
        fin>>y[i];
    }
    for( int i = 1; i <= n; ++ i ) {
        for( int j = 1; j <= m; ++ j ) {
            if ( x[i] == y[j] ) {
                d[i][j] = d[ i-1 ][ j-1 ];
                d[i][j].push_back( x[i] );
            } else {
                if ( d[ i-1 ][ j ].size() > d[ i ][ j-1 ].size() ) {
                    d[i][j] = d[ i-1 ][ j ];
                } else {
                    d[i][j] = d[ i ][ j-1 ];
                }
            }
        }
    }
    fout<<d[n][m].size()<<'\n';
    for( int i = 0; i < (int)d[n][m].size(); ++ i ) {
        fout<<d[n][m][i]<<' ';
    }
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}
