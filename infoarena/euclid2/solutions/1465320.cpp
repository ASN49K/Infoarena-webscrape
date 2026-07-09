# include <fstream>
using namespace std;
int cmmdc (int x, int y)
{
    int r;
    while (y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int i, a, b, t;
    f>>t;
    for (i=1; i<=t; i++)
    {
        f>>a>>b;
        g<<cmmdc(a, b)<<"\n";
    }
}
