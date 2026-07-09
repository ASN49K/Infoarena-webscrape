#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax=1030;

int n,m,d[Nmax][Nmax],a[Nmax],b[Nmax],sol[Nmax],best,k=1;

int maxim ( int x , int y ){
    if ( x > y )
        return x;
    return y;
}

int main()
{
    fin>>n>>m;
    for ( int i=1 ; i<=n ; i++ )
        fin>>a[i];
    for ( int i=1 ; i<=m ; i++ )
        fin>>b[i];
    for ( int i=1 ; i<=n ; i++ ){
        for ( int j=1 ; j<=m ; j++ ){
            if ( a[i] == b[j] )
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
            if ( d[i][j] > best ){
                best=d[i][j];
                sol[k++]=a[i];
            }
        }
    }
    fout<<d[n][m]<<'\n';
    for ( int i=1 ; i<=d[n][m] ; i++ )
        fout<<sol[i]<<' ';
}
