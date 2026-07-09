#include <fstream>
using namespace std;
ifstream in ("joc.in");
ofstream out ("joc.out");
int stare(int x,int rez)
{
    return x^rez;
}
int main()
{
    int n,rez,k;
    in>>n;
    for (int j=1;j<=n;++j)
    {
    int p;
    in>>p;
    in>>k;
    rez=k;
    for (int i=1; i<=p-1; ++i)
    {
        in>>k;
        rez=stare(k,rez);
    }
    if (rez==0)
        out<<"NU\n";
           else
               out<<"DA\n";
    }
    return 0;
}
