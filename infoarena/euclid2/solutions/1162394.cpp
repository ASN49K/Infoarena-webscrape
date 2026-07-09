#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,aux,T,i;

int main()
{
    f>>T;
    for (i=0;i<T;i++)
    {
        f>>a>>b;
        while (a!=0 && b!=0)
        {
            if (a>b)
            {
                aux=b;
                b=a%b;
                a=aux;
            }
            else
            {
                aux=a;
                a=b%a;
                b=aux;
            }
        }
        g<<max(a,b)<<'\n';
    }
    f.close();g.close();
    return 0;
}
