#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int b, n, a, i;
void cmmdc_aka_euclid(int x, int y)
{
    int c;
    while( b )
    {
        c = a%b;
        a = b;
        b = c;
    }
    g << a << "\n";
}
int main()
{
    f >> n;
    for( ; n--; n)
    {
        f >> a >> b ;
        cmmdc_aka_euclid(a , b);

    }
    return 0;
}
