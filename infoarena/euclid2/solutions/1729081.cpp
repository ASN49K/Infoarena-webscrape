#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in") ;
ofstream fout("euclid2.out") ;

int gcd(int a, int b)
{
    if(b == 0)
        return a ;
    else return gcd(b, a % b) ;
}

int gcd2(int a, int b)
{
    if(a == b)
        return a ;
    else if(a > b)
        return gcd2(a - b, b) ;
    else return gcd2(a, b - a) ;
}


int main()
{
    int n ;

    fin >> n ;

    while(n --)
    {int a, b ;
        fin >> a >> b ;
        fout << gcd(a, b) << '\n';

    }

    return 0;
}
