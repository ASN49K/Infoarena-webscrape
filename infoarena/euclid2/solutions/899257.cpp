#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b, r;
    fin >> n;
    for( int i = 1; i <= n; ++i )
    {
        fin >> a >> b;
        r = a % b;
        while( r )
        {
            a = b;
            b = r;
            r = a % b;
        }
        fout << b << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
