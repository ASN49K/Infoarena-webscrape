#include <fstream>
using namespace std;
ofstream fout ("cmlsc.out");
ifstream fin ("cmlsc.in");
int d[1030][1030],a[1030],b[1030],rez[1030],n,m,poz;
int main()
{
    fin>>m>>n;
    for(int i = 1 ; i <= m ; i++) fin>>a[ i ];
    for(int i = 1 ; i <= n ; i++) fin>>b[ i ];
    for(int i = 1 ; i <= m ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if( a[ i ] == b[ j ]) d[ i ][ j ] = d[ i - 1 ][ j - 1 ] + 1;
            else d[ i ][ j ] = max( d[ i - 1 ][ j ] , d[ i ][ j - 1 ]);
        }
    }
    for( int i = m , j = n ; i && j ;)
    {
        if( a[ i ] == b[ j ] ) rez[ ++poz ] = a[ i ] , i-- , j-- ;
        else if( d[ i ][ j - 1 ] < d[ i - 1 ][ j ] ) i--;
        else j--;
    }
    fout<<poz<<'\n';
    for( int i = poz ; i ; i--) fout<<rez[ i ]<<" ";
}
