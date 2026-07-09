#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out");

int main()
{
    int i , a , n , b;
    fin >> n ;
    for ( i = 1 ; i <= n ; i++ )
    {
        fin >> a >> b;
        fout << __gcd(a,b) << '\n' ;
    }
}
