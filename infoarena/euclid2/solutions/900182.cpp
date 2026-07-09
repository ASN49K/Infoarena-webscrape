#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int main()
{
    int n;
    int a, b, c;

    is >> n;

    for( int i = 0; i < n ; ++i )
    {
        is >> a >> b;
        if( a > b )
            c = b;
        else
            c = a;


        for( int j = c; j >= 1; j -= 2 )
        if( a % j == 0 && b % j == 0 )
            {
                os << j;
                break;
            }
        os << '\n';
    }


    is.close();
    os.close();
    return 0;
}
