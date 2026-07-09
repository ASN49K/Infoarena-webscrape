#include <fstream>
using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int Divizor(int x, int y);

int T, a, b, r, d;

int main()
{   is >> T;
    for(int i = 0; i < T; i++)
    {
        is >> a;
        is >> b;
        d = Divizor( a, b);
        os << d << '\n';
    }
    is.close();
    os.close();
    return 0;
}

int Divizor(int x, int y)
{
    if(y == 0) return x;
    do
    {
        r = x % y;
        x = y;
        y = r;
    }while(r);
    return x;


}
