#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in") ;
ofstream fout("nim.out") ;

int main()
{
    int ii , t , n , i , s,x;
    fin >> t;
    for ( ii = 1 ; ii <= t ; ii++ )
    {
        fin >> n ;
        s = 0 ;
        for ( i = 1 ; i <= n ; i++ )
        {
            fin >> x ;
            s = s^x ;
        }
        if ( s == 0 )
            fout << "NU" << '\n' ;
        else
            fout << "DA" << '\n' ;
    }
}
