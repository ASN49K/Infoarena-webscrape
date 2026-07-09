#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,i,r,aux;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
