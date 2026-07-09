#include <fstream>

using namespace std;

 ifstream x ("euclid2.in");
 ofstream y ("euclid2.out");

 int T;

int main()
{
    int i;

    x>>T;

    int a,b,c,aux;

    for(i=1;i<=T;i++)
    {
        x>>a>>b;

        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }

        while(a%b!=0)
        {
            a=a%b;

            aux=a;
            a=b;
            b=aux;
        }
//        y<<a<<' ';
        y<<b<<'\n';
    }

    return 0;
}
