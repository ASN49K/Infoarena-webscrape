#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,i,a,b;

int euclid(int x, int y)
{
    int A,B,r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
