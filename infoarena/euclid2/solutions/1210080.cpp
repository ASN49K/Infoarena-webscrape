#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b);
int T, x, y;

int main()
{
    fin >> T;
    for ( int i = 0; i < T; ++i )
    {
        fin >> x >> y;
        fout << cmmdc( x , y ) << '\n';
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
