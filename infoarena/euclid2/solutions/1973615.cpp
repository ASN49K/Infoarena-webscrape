#include <iostream>
#include <fstream>

#define ll long long


using namespace std;

ifstream  fin("euclid2.in");
ofstream fout("euclid2.out");

int T;

ll gcd( ll a, ll b )
{
    while( b )
    {
        ll emp = a % b;
        a = b;
        b = emp;
    }
    return a;
}


int main()
{
    fin >> T;

    while( T-- )
    {
        ll a, b;
        fin >> a >> b;
        fout << gcd( a, b ) << "\n";
    }

    return 0;
}
