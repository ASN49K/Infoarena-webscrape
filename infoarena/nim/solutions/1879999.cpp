#include <fstream>
#include <cstdio>
using namespace std;

ofstream g("nim.out");

int x,t,n,s;

int main()
{
    freopen("nim.in","r",stdin);
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        s = 0;
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            s=s^x;
        }
        if (s==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }

    return 0;
}
