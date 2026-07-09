#include <fstream>

using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int main ()
{
    int a, b, c, i, n;
    is >> n;
    for ( i = 1; i <= n; i++ )
    {   is >> a >> b;
        c = a % b;
        while ( c != 0 )
        {
            a = b;
            b = c;
            c = a % b;
        }
    os << b << "\n" ;
    }


    is.close();
    os.close();
    return 0;
}
