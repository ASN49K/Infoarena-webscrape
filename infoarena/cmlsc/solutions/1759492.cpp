#include <fstream>
#include <cmath>

using namespace std;

ifstream fin( "cmlsc.in" );
ofstream fout( "cmlsc.out" );

int Lmax[1025][1025],n,m, X[1025], Y[1025],v[1025];
int main()
{
    fin>>n>>m;
    for( int i=1; i<=n; i++ )
        fin>>X[i];
    for( int i=1; i<=m; i++ )
        fin>>Y[i];

    for( int i=2; i<=n; i++ )
    {
        for( int j=2; j<=m; j++ )
        {
            if( X[i]==Y[j] )
                Lmax[i][j]=Lmax[i-1][j-1]+1;
            else
                Lmax[i][j]=max( Lmax[i-1][j], Lmax[i][j-1] );
        }

    }
    fout<<Lmax[n][m]<<'\n';
    int a=n,b=m;
    while(a!=1 && b!=1)
    {
        if(Lmax[a][b-1]!=Lmax[a][b] && Lmax[a-1][b]!=Lmax[a][b])
        {
            v[++v[0]]=X[a];
            a--;b--;
        }
        else
        {
            if(Lmax[a][b-1]!=Lmax[a][b])
                a--;
            else
                b--;
        }
    }
    for(int i=v[0];i>=1;i--){
        fout<<v[i];
        if(i!=1)
            fout<<' ';
    }

    return 0;
}
