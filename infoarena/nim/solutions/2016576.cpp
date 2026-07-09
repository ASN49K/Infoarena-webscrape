#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
unsigned long long n,sxor,i,m,j,a;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>m;
        sxor=0;
        for(j=1;j<=m;j++)
        {
            f>>a;
            sxor=sxor^a;
        }
        if(sxor)
        {
            g<<"DA"<<'\n';
        }
        else
        {
            g<<"NU"<<'\n';
        }
    }
    return 0;
}
