#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n,a,b,aux,i,r;
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        do
        {
            r=a%b;
            a=b;
            b=r;
        }while(r!=0);
        g<<a<<'\n';
    }
    g.close();
    return 0;
}
