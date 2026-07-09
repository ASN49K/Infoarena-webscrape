#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int  N_MAX = 1025 ;
int A[N_MAX],
    B[N_MAX],
    n,
    m,
    cmlsc[N_MAX][N_MAX],
    result[N_MAX],
    resPos = 0;
vector< int > R;
int main()
{


    in >> m;                                        //citim m(lungimea lui A)
    in >> n;                                        //citim n (lungimea lui B)

    for(int i = 1 ; i <= m ; i ++)
        in >> A[i],                                 //citim elementele lui A
        cmlsc[ i ][ 0 ] =  0;

    for(int i = 1 ; i <= n ; i++ )
        in >> B[i],                                 //citim elementele lui B
        cmlsc[ i ][ 0 ] = 0;

    for(int i = 1 ;  i <= m ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if( A[i] == B[j] )
                cmlsc[ i ][ j ] = 1 + cmlsc[ i-1 ][ j-1 ];      //daca caracterele de pe pozitia i in A si j in B sunt egale marim dimensiunea celui mai lung subsir comun
            else
                cmlsc[ i ][ j ] = max( cmlsc[ i-1 ][ j ] , cmlsc[ i ][ j-1 ]);
    //altfel cel mai lung subsir comn va fi lungimea maxima a celui mai lung subsir comun care se formeaza
    //cu cel mai lung subsir comun intre primele i-1 elemente din A si primele j elemente din B sau primele i elemente
    //din A si primele j-1 elemente din B

    int i =  m ; int j = n;
    while( i > 0 && j > 0)
    {
        if( A[ i ] == B[ j ])
                result[ ++resPos ] = A[i] ,i--,j--;
        else
        {
            if(cmlsc[ i-1 ][ j ] > cmlsc[ i ][ j-1 ])
                i--;
            else
                j--;
        }
    }
    for( i = resPos  ; i > 0  ; i--)
        out << result[  i ] << " ";
    out << "\n" << cmlsc[ m ][ n ];
    return 0;
}
