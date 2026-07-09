#include<fstream>
#include<vector>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

const int nmax = 1024;
short int x[ nmax + 1 ], y[ nmax + 1 ];
vector <short int> d[ 2 ][ nmax + 1 ];

int main()
{
    int n, m, ind;
    fin>>n>>m;
    for( int i = 1; i <= n; ++ i ) {
        fin>>x[i];
    }
    for( int i = 1; i <= m; ++ i ) {
        fin>>y[i];
    }
    ind = 1;
    for( int i = 1; i <= n; ++ i ) {
        for( int j = 1; j <= m; ++ j ) {
            if ( x[i] == y[j] ) {
                d[ind][j] = d[ 1-ind ][ j-1 ];
                d[ind][j].push_back( x[i] );
            } else {
                if ( d[ 1-ind ][ j ].size() > d[ ind ][ j-1 ].size() ) {
                    d[ind][j] = d[ 1-ind ][ j ];
                } else {
                    d[ind][j] = d[ 1-ind ][ j-1 ];
                }
            }
        }
        ind = 1 - ind;
    }
    ind = 1 - ind;
    fout<<d[ind][m].size()<<'\n';
    for( int i = 0; i < (int)d[ind][m].size(); ++ i ) {
        fout<<d[ind][m][i]<<' ';
    }
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}
