#include <iostream>
#include <fstream>
using namespace std;
int t, n, a, xorsum;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    f>>t;
    while(t!=0)
    {
        t--;
        f>>n;
        xorsum=0;
        for(int i=1; i<=n; i++)
        {
            f>>a;
            xorsum=xorsum^a;
        }
        if(xorsum!=0)
            g<<"DA"<<'\n';   //N-position
        else
            g<<"NU"<<'\n';   //P-positon
    }
    f.close();
    g.close();
    return 0;
}
