#include <fstream>
using namespace std;
fstream f("Euclid2.in",ios::in);
fstream g("Euclid2.out",ios::out);
long a,b,i,t,v[100];
int div(long m,long n)
{
    long c=m%n;
    while (c!=0)
    {
        m=n;
        n=c;
        c=m%n;
    }
    return n;
}
int main ()
{
    f>>t;
    for (i=1;i<=t;i++)
        {
            f>>a>>b;
            v[i]=div(a,b);
        }
    for (i=1;i<=t;i++)
        g<<v[i]<<'\n';
        f.close();
        g.close();
    return 0;
}
