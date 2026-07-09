#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("nim.in") ;
ofstream fout ("nim.out") ;

int t ;

int main()
{
    fin >> t ;
    int n , el , sum ;
    while ( t )
    {
        int i = 1 ;
        for ( sum = 0 , fin >> n ; i <= n ; ++ i )
               fin >> el , sum ^= el ;

        if ( sum == 0 )
                 fout << "NU\n" ;
        else
                 fout << "DA\n" ;
     -- t ;
    }

    return 0;
}
