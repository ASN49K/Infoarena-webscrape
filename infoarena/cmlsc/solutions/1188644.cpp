#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[257],n,m,b[1025],c[1025],y;
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;++i)
    {
        f>>b[i];
        a[b[i]]++;
    }
    for(int i=1;i<=n;++i)
    {
        f>>c[i];
        a[c[i]]++;
        if(a[c[i]]>1)
            ++y;
    }
    int x=256;
    g<<y<<'\n';
    for(int i=1;i<=x;++i)
    {
        if(a[i]>1)
            g<<i<<' ';
    }
    g.close();
    return 0;
}
