#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    short int T,a,b,i,d=1,aux,j;
    fstream f("euclid2.in");
    fstream g("euclid2.out");
    f>>T;
    for (i=1;i<=T;i++)
    {
        f>>a>>b;
        if (b>a)
        {
            aux=a;
            a=b;
            b=aux;
        }
        for (j=2;j<=a/2;j++)
        {
            if (a%j==0 and b%j==0)
            {
                d=j;
            }
        }
        g<<d<<"\n";
        d=1;
    }
    f.close(),g.close();
    return 0;
}
