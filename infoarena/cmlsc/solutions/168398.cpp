#include <iostream>
#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAXN 1024

int N[MAXN],M[MAXN],D[MAXN][MAXN],n,m,nr;

void read_data()
{
    freopen ( FIN , "r" , stdin );
    scanf ("%d %d" , &n , &m);
    int i;
    for ( i=0 ; i<n ; i++ ) scanf ( "%d" , &N[i+1] );
    for ( i=0 ; i<m ; i++ ) scanf ( "%d" , &M[i+1] );
    fclose (stdin);
}

void write_data()
{
    freopen ( FOUT , "w" , stdout );
    printf ( "%d\n" , nr );
    for ( int i=0 ; i<nr ; i++ )
        printf ( (i<nr-1)?"%d ":"%d\n" , N[i] );
    fclose (stdout);
}

int max(int x , int y) { return (x>y)?(x):(y); }

void cmlsc()
{
    int i,j;
    nr=0;
    for ( i=1 ; i<=n ; i++ )
        for ( j=1 ; j<=m ; j++ )
            if (N[i]==M[j])
            {
                D[i][j]=D[i-1][j-1]+1;
                if (D[i][j]>nr) N[nr++]=N[i];
            } else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
}

int main()
{
    read_data();
    cmlsc();
    write_data();
    return 0;
}
