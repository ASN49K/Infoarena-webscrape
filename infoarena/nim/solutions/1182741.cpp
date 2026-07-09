#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");
int xo,n,v[10001],t;
int main()
{
    f>>t;
    for(int j=1;j<=t;j++)
    {
        f>>n;
        for(int i=1;i<=n;i++)
            f>>v[i];
        xo=v[1];
        for(int i=2;i<=n;i++)
            xo=xo^v[i];
        if(xo==0)
            g<<"NU"<<endl;
        else
            g<<"DA"<<endl;
    }
    return 0;
}
