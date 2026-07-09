#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int N,M,A[1025],B[1025],T[1025][1025],sol[1025],lg;

int main()
{
    f >> N >> M;
    for ( int i = 1; i <= N; i++) f >> A[i];
    for ( int i = 1; i <= M; i++) f >> B[i];

    for ( int i = 1; i <= N ; i++ )
    {
        for ( int j = 1; j <= M; j++ )
        {
            if ( A[i] == B[j] )
            {
                T[i][j] = T[i-1][j-1] + 1;
            }
            else
                T[i][j] = max(T[i-1][j], T[i][j-1]) ;
        }
    }
    int i = N , j = M;
    while ( i >= 1 and j >= 1 )
    {
        if ( T[i-1][j] == T[i][j-1] and T[i][j] == T[i-1][j-1] + 1 )
        {
            sol[++lg] = A[i];
            i--;
            j--;
        }
        else
        {
            if ( T[i-1][j] > T[i][j-1] )
            {
                i--;
            }
            else
                j--;
        }
    }
    g << lg << "\n" ;
    for ( int i = lg; i >=1 ; i-- )
        g << sol[i] << " " ;

    return 0;
}
