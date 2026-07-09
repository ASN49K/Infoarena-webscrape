#include <fstream>

int a,b,q,i;

using namespace std;

fstream f,g;

int main()
{
    f.open("euclid2.in",ios_base::in);
    g.open("euclid2.out",ios_base::out);
    f>>q;
    for(i=1;i<=q;i++)
    {
        f>>a>>b;
        while(a!=0&&b!=0)
        {
            if(a>b)a=a%b;
            else b=b%a;
        }
        g<<a+b<<'\n';
    }
}
