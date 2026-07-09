#include <stdio.h>

unsigned char N[1024],M[1024];
short C[1024][1024];

int main ()
{
    int i,j,n,m,r;
    freopen ( "cmlsc.in" , "r" , stdin );
    scanf ( "%d %d" , &n , &m );
    for ( i=0 ; i<n ; i++ ) scanf ( "%d" , &N[i] );
    for ( i=0 ; i<m ; i++ ) scanf ( "%d" , &M[i] );
    fclose ( stdin );

    for (r=i=0 ; i<n ; i++)
    {
        r|= (bool) (N[i]==M[0]);
        C[i][0]=r;
    }
    for (r=i=0 ; i<m ; i++)
    {
        r|= (bool) (N[0]==M[i]);
        C[0][i]=r;
    }
    for ( i=1 ; i<n ; i++ )
        for ( j=1 ; j<m ; j++ )
            if (N[i]==N[j]) C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=(C[i-1][j]>C[i][j-1])?C[i-1][j]:C[i][j-1];

    freopen ( "cmlsc.out" , "w" , stdout );
    printf ( "%d\n" );
    for ( i=0,r=1 ; i<n ; i++ )
        for ( j=0 ; j<m ; j++ )
            if (C[i][j]==r)
            {
                if (r==C[n-1][m-1]) printf ( "%d\n" , N[i] );
                else printf ( "%d " , N[i] );
            }
    fclose ( stdout );
}
