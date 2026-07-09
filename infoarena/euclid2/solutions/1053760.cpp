#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    if (y > x)
    {
        int aux=x;
        x=y;
        y=x;
    }
    int r=x%y;
    while(r)
    {
        x=y;y=r;r=x%y;
    }
    return y;
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
