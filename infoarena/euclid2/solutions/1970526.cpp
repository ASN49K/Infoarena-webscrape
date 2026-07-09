#include<fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int a, b, t;
int euclid(int m, int n)
{
    int r;
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
