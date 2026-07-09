#include <fstream>

using namespace std;

#define DIM 100001

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b);
int T, a[DIM], b[DIM];

int main()
{
    fin >> T;
    for ( int i = 0; i < T; ++i )
    {
        fin >> a[i] >> b[i];
        fout << cmmdc( a[i] , b[i] ) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}

int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc( b, a % b );
}
