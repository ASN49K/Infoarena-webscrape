#include <iostream>
#include <fstream>
using namespace std;
int cmmdc( int n, int m )
{
    while( n != 0 )
    {
        int r = n % m;
        m = n;
        n = r;
    }
    return m;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin >> T;
    for( int i = 1 ; i <= T ; ++i )
    {
        int n , m;
        fin >> n >> m;
        fout << cmmdc( n , m ) << '\n';
    }
}
