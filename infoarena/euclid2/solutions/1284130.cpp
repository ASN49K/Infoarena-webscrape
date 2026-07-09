#include <fstream>

using namespace std;

int main()
{
    int T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    int aux,i=0;
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
            aux=b;
            b=a%b;
            a=b;
        }
        g<<b<<endl;
    }
    f.close();
    g.close();
    return 0;
}
