#include <fstream>

using namespace std;
int div(int e,int c)
{
    int r;
    while(c!=0)
    {
        r=e%c;
        e=c;
        c=r;
    }
    return e;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,i,a,b;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
        g<<div(a,b)<<'\n';
    }
    f.close();
    g.close();

    return 0;
}
