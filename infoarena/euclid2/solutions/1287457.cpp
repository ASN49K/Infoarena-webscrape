#include <fstream>

using namespace std;

int main()
{
    long T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    long aux,i=0;
    for(;i<T;++i)
    {
        f>>a>>b;
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        while(a%b!=0)
        {
            aux=a;
            a=b;
            b=aux%b;
        }
        g<<b<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
