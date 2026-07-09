#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int a,b,aux,i,r;
int main()
{
    fin>>n;
    for (i=1;i<=n;i++)
    {
        fin>>a>>b;
        if (b>a)
        {
            aux=a;
            a=b;
            b=aux;
            }
        r=a%b;
        a=b;
        b=r;
        while (r>0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        fout<<a<<"\n";
    }
}
