#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, t;
int euclid(int m, int n)
{
    int r;
    if(n==0 or m==0)
        return n+m;
    while(n)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
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
