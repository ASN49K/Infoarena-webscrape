#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a, b, t;
int euclid(long long m, long long n)
{
    int r;

    while(n)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
    if(m==1)
        g<<0;
    else
        g<<m;
}
int main()
{
    f>>t;
    while(t)
    {
        f>>a>>b;
        g<<euclid(a, b)<<endl;
        t--;
    }
    f.close();
    g.close();
    return 0;
}
