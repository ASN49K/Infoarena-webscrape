#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int cmlsc[1025][1025], dir[1025][1025];
int A[1025], B[1025];

#define DIAGONALA 0
#define SUS 1
#define STANGA 2

int reconstruct_cmlsc( int i, int j )
{
    if( i == 0 || j == 0 )
        return 0;
    else
    {
        if( dir[i][j] == DIAGONALA )
        {
            reconstruct_cmlsc( i-1, j-1 );
            g << A[i] << " ";
        }
        else if( dir[i][j] == SUS )
            reconstruct_cmlsc( i-1, j );
        else
            reconstruct_cmlsc( i, j-1 );
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    f.tie(nullptr);
    g.tie(nullptr);

    int n, m;
    f >> n >> m;
    for( int i = 1; i <= n; ++i )
        f >> A[i];
    for( int i = 1; i <= m; ++i )
        f >> B[i];
    for( int i = 1; i <= n; ++i )
    {
        for( int j = 1; j <= m; ++j )
        {
            if( A[i] == B[j] )
            {
                cmlsc[i][j] = cmlsc[i-1][j-1] + 1;
                dir[i][j] = DIAGONALA;
            }
            else
            {
                cmlsc[i][j] = cmlsc[i-1][j];
                dir[i][j] = SUS;
                if( cmlsc[i][j] < cmlsc[i][j-1] )
                    cmlsc[i][j] = cmlsc[i][j-1], dir[i][j] = STANGA;
            }
        }
    }
    g << cmlsc[n][m] << "\n";
    reconstruct_cmlsc(n, m);
    return 0;
}