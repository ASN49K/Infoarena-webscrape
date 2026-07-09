#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,nr,k,poz,ma,a[1030],b[1030],sol[1030],pos[1030];
int main()
{
    f>>n>>m;
    for(i=1 ; i<=n ; ++i)
       f>>a[i];
    for(i=1 ; i<=n ; ++i)
        f>>b[i];

    ma=0;
    for(k=1 ; k<=n ; ++k)
    {
        poz=0;
        nr=0;
        for(i=k ; i<=n ; ++i)
        {
            for(j=poz+1 ; j<=m ; ++j)
                if(a[i]==b[j])
            {
                pos[++nr]=a[i];
                poz=j;
                break;
            }
        }
       if(nr>ma)
       {
           ma=nr;
           for(i=1 ; i<=ma ; ++i)
            sol[i]=pos[i];
       }
    }
    g<<ma<<'\n';
    for(i=1 ; i<=ma ; ++i)
        g<<sol[i]<<" ";
    g<<'\n';
    return 0;
}
