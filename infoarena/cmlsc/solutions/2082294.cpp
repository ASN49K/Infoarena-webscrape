#include <iostream>
#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[ 1024 ], b[ 1024 ], d[ 1024 ][ 1024 ], sir[ 1024 ], lcs;

int main(){
    int i, j;
    fin >> m >> n;
    for(i = 1; i <= m; i++)
        fin >> a[ i ];
    for(i = 1; i <= n; i++)
        fin >> b[ i ];
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(a[ i ] == b[ j ])
                d[ i ][ j ] = 1 + d[ i-1 ][ j-1 ];
            else
                d[ i ][ j ] = maxim(d[ i-1 ][ j ], d[ i ][ j-1 ]);
    for(i = m, j = n; i; )
        if(a[ i ] == b[ j ])
            sir[++lcs] = a[ i ], --i, --j;
        else if(d[ i-1 ][ j ] < d[ i ][ j-1 ])
            --j;
        else
            --i;
        fout << lcs << '\n';
        for(i = lcs; i; --i)
            fout << sir[ i ] << ' ';
        return 0;
}
