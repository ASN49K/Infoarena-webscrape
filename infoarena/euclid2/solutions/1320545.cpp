#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;
int cmmdc(int x, int y);

int main()
{
    fin >> T;
    for ( ; T; --T )
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}

int cmmdc(int x, int y)
{
    if ( x % y == 0 )
        return y;
    return cmmdc(y, x % y);
}
