
#include <fstream>

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
long long c,i,j,n;
long long s,a;
int main()
{
    f>>c;
    for(i=1;i<=c;i++)
    {
        s=0;
        f>>n;
        for(j=1;j<=n;j++)
        {
            f>>a;


            s=s^a;

        }
        if(s==0)
            g<<"NU";
        else
            g<<"DA";
        g<<'\n';
    }
    return 0;
}
