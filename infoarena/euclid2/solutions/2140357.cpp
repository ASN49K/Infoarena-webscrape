#include <fstream>
#include <cstring>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
char w[1000];
int v[1000];
int main()
{
    int n,i,x,y,r,aux;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        if(y<x)
        {
            aux=x;
            x=y;
            y=aux;
        }
        while(y%x!=0)
        {
            r=y%x;
            y=x;
            x=r;
        }
        g<<x<<"\n";
    }

    return 0;
}
