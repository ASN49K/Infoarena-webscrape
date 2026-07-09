#include <stdio.h>
using namespace std;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    short int maxx=0,k=0,j,n,m,i,v[1025],v2[1025],v3[1025];
    bool ok;
    v3[0]=0;
    scanf("%hu%hu",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%hu",&v[i]);
    for(i=1; i<=m; i++)
        scanf("%hu",&v2[i]);
    for(i=1; i<=n; i++)
    {
        ok=false;
        for(j=1; j<=m; j++)
        {
            if(v[i]==v2[j] && j>k)
            {
                v3[i]=v3[i-1]+1;
                k=j;
                j=m;
                ok=true;
            }
        }
        if(!ok)
            v3[i]=v3[i-1];

    }
    for(i=1; i<=n; i++)
    {
        if(v3[i]>v3[i-1])
            maxx++;
    }
    printf("%hu\n",maxx);
    for(i=1; i<=n; i++)
    {
        if(v3[i]>v3[i-1])
            printf("%hu ",v[i]);
    }
    return 0;
}
