#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int T,i,j,n;
long long s,x;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        s=0;
        f>>n;
        for(j=1;j<=n;j++)
        {
            f>>x;
            s=s^x;
        }
        if(s==0)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
    return 0;
}
