#include<fstream>

using namespace std;

int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,T,c,i;
    f>>T;
    for(i=0;i<T;i++)
    {
        f>>a>>b;
        c=euclid(a,b);
        g<<c;
        g<<'\n';
    }
    f.close();
    g.close();
}
