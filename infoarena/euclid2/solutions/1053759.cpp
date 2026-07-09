#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    if (y == 0)
        return x;
    else
        return cmmdc(y, x % y);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,n2;
    f>>n>>n2;
    g<<cmmdc(n,n2);
    f.close();
    g.close();
    return 0;
}
