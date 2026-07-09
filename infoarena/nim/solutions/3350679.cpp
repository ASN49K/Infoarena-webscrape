#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nim.in") ;
ofstream fout ("nim.out") ;

void solve ()
{
    int q ;
    fin >> q ;
    while ( q -- )
    {
        int n ;
        fin >> n ;
        bool ok = 0 ;
        int cnt = 0 ;
        for ( int i = 1 ; i <= n ; i ++ )
        {
            int x ;
            fin >> x ;
            if ( x == 1 && ok == 0 )
                cnt ++ ;
            else if ( x != 1 )
                ok = 1 ;
        }
        if ( cnt % 2 == 0 )
            fout << "DA" ;
        else
            fout << "NU" ;
        fout << '\n' ;
    }
}

signed main ()
{
    std :: ios_base :: sync_with_stdio ( false ) ;
    fin.tie(0) ;
    fout.tie(0) ;
    solve () ;
}
