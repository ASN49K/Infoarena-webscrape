#include <bits/stdc++.h>
using namespace std;

ifstream fin ("euclid2.in") ;
ofstream fout ("euclid2.out") ;


int main()
{
    int n ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; i ++ )
    {
        long long x , y ;
        fin >> x >> y ;
        fout << __gcd(x,y) << '\n' ;
    }

    return 0;
}
