#include<fstream>
#include<iostream>

#define INfile "nim.in"
#define OUTfile "nim.out"

using namespace std;

ifstream F ( INfile ) ;
ofstream G ( OUTfile ) ;

int N ;

void read () ;
void solve () ;

int main ()
{
    read () ;
    solve () ;

    F.close () ;
    G.close () ;

    return 0 ;
}

void read ()
{
    F >> N ;
}

void solve ()
{
    int i , j , S , nr , x ;
    for ( i = 1 ; i <= N ; ++ i )
    {
        F >> nr ;
        F >> S ;
        for ( j = 2 ; j <= nr ; ++ j )
        {
            F >> x ;
            S ^= x ;
        }
        if ( S )
            G << "DA\n" ;
        else
            G << "NU\n" ;
    }
}
