#include <bits/stdc++.h>


using namespace std ;

ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out") ;

int gcd(int a, int b)
{
    if(b == 0)
        return a ;
    else return gcd(b, a % b) ;
}

int main()
{
    int N, A, B ;

    fin >> N ;

    while(N --){

    fin >> A >> B ;
    fout << gcd(A, B) << '\n';

    }
    fin.close() ;
    fout.close() ;
    return  0 ;
}
