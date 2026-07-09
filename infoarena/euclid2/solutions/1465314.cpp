#include <fstream.h>
int div(int x, int y)
{
    while (y!=0)
    {
        x=y;
        y=x%y;
    }
    return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t, a, b, i;
    f>>t;
    for(i=1; i<=t; i++)
    {   f>>a>>b;
        g<<div(a, b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
