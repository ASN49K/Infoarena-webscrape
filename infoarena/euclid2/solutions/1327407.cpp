#include<iostream>
#include<fstream>
using namespace std ;
ifstream fin ( "euclid2.in" ) ;
ofstream fout ( "euclid2.out" ) ;
int main()
{
    int t , a , b , d , aux , g ;
    fin>>t ;
    while ( fin>>a>>b )
    {
        if ( a>b )
        {
            aux=a ;
            a=b ;
            b=aux ;
        }
        d=a ;
        g=0 ;
        while ( g!=1 )
            if ( a%d==0 and b%d==0 )
            {
                fout<<d<<endl ;
                g=1 ;
            }
            else
                d-- ;
    }
    return 0 ;
}
