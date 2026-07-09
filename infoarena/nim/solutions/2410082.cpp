#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,s,i,j,x;
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;s=0;
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
