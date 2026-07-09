#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int CMMDC(int a, int b);
int a, b, n;

int main()
{
    fin >> n;
    for ( int i = 1; i <= n; ++i )
    {
        fin >> a >> b;
        fout << CMMDC(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}

int CMMDC(int a, int b)
{
    if ( b == 0 ) return a;
    return CMMDC(b, a % b);
}
