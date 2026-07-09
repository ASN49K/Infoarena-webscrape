#include<cstdio>
#include<algorithm>
using namespace std;
int c,i,j,n,m,w[1025],v[1025],sol,o[1024],z,rez;
int main ()
{
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    scanf ("%d %d",&n,&m);
    for (i=1;i<=n;++i) scanf ("%d",&v[i]);
    for (i=1;i<=m;++i) scanf ("%d",&w[i]);
    if (n<m)
    {
        for (i=1;i<=n;++i)
        {
            c=0;
            for (j=1;j<=m;++j)
            {
                if (w[j]==v[i]) {c=1;break;}
            }
            if (c==1)
            {++sol;o[++z]=v[i];}
        }
    }
    if (n>m)
    {
        for (i=1;i<=m;++i)
        {
            c=0;
            for (j=1;j<=n;++j)
            {
                if (w[i]==v[j]) {c=1;break;}
            }
            if (c==1)
            {++sol;o[++z]=w[i];}
        }
    }
    printf ("%d\n",sol);
    for (i=1;i<=z;++i) {printf ("%d ",o[i]);}
    return 0;
}
