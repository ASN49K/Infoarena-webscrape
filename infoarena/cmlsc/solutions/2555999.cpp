#include <iostream>
#include <fstream>

using namespace std;

const int NMAX = 1100;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
short x[NMAX], y[NMAX];
int v[NMAX];
int DP[NMAX][NMAX];

void Read()
{
    fin >> N >> M;

    for( int i = 1; i <= N; ++i )
        fin >> x[i];
    for( int j = 1; j <= M; ++j )
        fin >> y[j];
}
void LCS( int i, int j )
{
    if( i == 0 || j == 0 ) return;
    if( x[i] == y[j] )
    {
        LCS( i-1, j-1 );
        DP[i][j] = 1 + DP[i-1][j-1];
    }
    else
    {
        LCS( i, j-1 );
        LCS( i-1, j );
        DP[i][j] = max( DP[i-1][j], DP[i][j-1] );
    }
}

void Path( int i, int j )
{
    if( !i || !j ) return;

    if( x[i] == y[j] )
    {
        Path( i-1, j-1 );
        fout << x[i] << ' ';
    }
    else
    {
        if( DP[i-1][j] == DP[i][j] )
            Path( i-1, j );
        else Path( i, j-1 );
    }
}
void Solve()
{
    for( int i = 1; i <= N; ++i )
        for( int j = 1; j <= M; ++j )
        {
            if( x[i] == y[j] )DP[i][j] = 1 + DP[i-1][j-1];
            else DP[i][j] = max( DP[i-1][j], DP[i][j-1] );
        }
    fout << DP[N][M] << '\n';
    Path( N, M );

}
int main()
{
    Read();
    Solve();
    return 0;
}
