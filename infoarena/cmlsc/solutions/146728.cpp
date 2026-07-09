#include <stdio.h>

char N[1024],M[1024];
short C[1024][1024];

int main ()
{
    int i,j,n,m,r;
    freopen ( "cmlsc.in" , "r" , stdin );
    scanf ( "%d %d" , &n , &m );
    for ( i=0 ; i<n ; i++ )
    {
        scanf ( "%d" , &r );
        N[i]=r;
    }
    for ( i=0 ; i<m ; i++ )
    {
        scanf ( "%d" , &r );
        M[i]=r;
    }
    fclose ( stdin );

    for (r=i=0 ; i<n ; i++)
    {
        r = (r || (N[i]==M[0]))?(1):(0);
        C[i][0]=r;
    }

    for (r=i=0 ; i<m ; i++)
    {
        r= (r|| (N[0]==M[i]))?(1):(0);
        C[0][i]=r;
    }
    for ( i=1 ; i<n ; i++ )
        for ( j=1 ; j<m ; j++ )
            if (N[i]==M[j]) C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=(C[i-1][j]>C[i][j-1])?C[i-1][j]:C[i][j-1];

    freopen ( "cmlsc.out" , "w" , stdout );
    printf ( "%d\n" , C[n-1][m-1] );
    for ( i=0,r=1 ; i<n ; i++ )
        for ( j=0 ; j<m ; j++ )
            if (C[i][j]==r)
            {
                if (r==C[n-1][m-1]) printf ( "%d\n" , N[i] );
                else printf ( "%d " , N[i] );
                r++;
            }
    fclose ( stdout );
}
