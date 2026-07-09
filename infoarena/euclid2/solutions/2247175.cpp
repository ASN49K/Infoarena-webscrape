#include <fstream>
#define filein "euclid2.in"
#define fileout "euclid2.out"

using namespace std;
ifstream in(filein);
ofstream out(fileout);
unsigned int T;
unsigned int cmmdc(unsigned int x, unsigned int y)
{
    if(!y)
        return x;
    return cmmdc(y, x % y);
}
int main()
{
    in >> T;
    for(unsigned int i = 0; i != T; ++i)
    {
        unsigned int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
    return 0;
}
