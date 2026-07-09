# include <iostream.h>
# include <fstream.h>
int div(unsigned int x, unsigned int y)
{
    unsigned int r;
    while (y!=0)
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
    unsigned int t, a, b, cm;
    f>>t;
    f>>a>>b;
    cm=div(a, b);
    for(b=3; b<=t; b++)
    {   f>>a;
        cm=div(cm, a);
    }
    g<<cm;
    f.close();
    g.close();
    return 0;
}
