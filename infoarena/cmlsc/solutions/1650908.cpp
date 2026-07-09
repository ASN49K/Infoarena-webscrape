#include <fstream>

using namespace std ;

ifstream f ("cmlsc.in") ;
ofstream g ("cmlsc.out") ;

int A[1026], B[1026] ; //sirurile
int D[1026][1026], sir[1026] ; // matricea dinamicii si subsirul comun
int m , n , best, i, j ;

int main()
{
    f >> m >> n ;
    for (i = 1 ; i <= m ; i++ )
        f >> A[i] ;
    for (i = 1 ; i <= n ; i++ )
        f >> B[i] ;

    for (i = 1 ; i <= m ; i++ )
        for (j = 1 ; j <= n ; j++ )
            if ( A[i] == B[j] ) // cazul cand ultimul caracter e ,,comun"
                D[i][j] = 1 + D[i-1][j-1] ;
            else   //cazul cand alegi maximul dintre precedentii
                D[i][j] = max ( D[i-1][j] , D[i][j-1] ) ;
    //construim sirul
    int i=m, j=n;
    while (i!=0)
        if ( A[i] == B[j] ) {
            sir[++best] = A[i]; //avem caz de caracter comun
            i--;
            j--;
        }
        else if ( D[i-1][j] < D[i][j-1] )   // alegem care dintre cei 2 precedenti
                j--;
            else
                i--;

    g << best << "\n" ;
    for (i = best ; i > 0 ; i-- )
        g << sir[i] << " " ;

    return 0;
}
