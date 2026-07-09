#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, i, n1, n2;

int euclid ( int a, int b )
{
    if ( b == 0 )
    {
        return a;
    }
    else
    {
        return euclid ( b, a % b );
    }
}

int main()
{
    fin>>n;
    for ( i = 1; i <= n; i++ )
    {
        fin >> n1 >> n2;
        fout << euclid ( n1, n2 ) << '\n';
    }
}
