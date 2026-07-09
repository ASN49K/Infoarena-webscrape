#include <iostream>
#include <fstream>

#define NMAX 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[NMAX], y[NMAX];
int N, M;
int DP[NMAX][NMAX];

void Path(int i, int j){

    if( !i || !j )return;

    if( x[i] == y[j] ){

        Path( i-1, j-1 );
        fout << x[i] << ' ';
    }
    else{

        if( DP[i-1][j] == DP[i][j] )Path( i-1, j );
        else Path( i, j-1 );
    }
}
void Solve(){

    fin >> N >> M;

    for( int i = 1; i <= N; ++i )
            fin >> x[i];
    for( int j = 1; j <= M; ++j )
            fin >> y[j];


        for( int i = 1; i <= N; ++i )

        for( int j = 1; j <= M; ++j )

        {

            if( x[i] == y[j] )DP[i][j] = 1 + DP[i-1][j-1];

            else DP[i][j] = max( DP[i-1][j], DP[i][j-1] );

        }

    fout << DP[N][M] << '\n';

    Path( N, M );


}

int main(){

    Solve();
    return 0;
}
