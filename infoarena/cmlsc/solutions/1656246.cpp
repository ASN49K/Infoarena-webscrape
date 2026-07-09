#include <iostream>
#include <cstdio>
using namespace std;

const int nmax=102;

short a[nmax][nmax],v1[nmax],v2[nmax],v[nmax],n1,n2,x,y,x1,y1,x2,y2,k,kmax;

void citire()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n1,&n2);
    for(x=1;x<=n1;x++)
        scanf("%d",&v1[x]);
    for(y=1;y<=n2;y++)
        scanf("%d",&v2[y]);
}

int main()
{
    citire();

    for(x=1;x<=n1;x++)
        for(y=1;y<=n2;y++)
            if(v1[x]==v2[y])
            {
                k=0;
                for(x1=1;x1<x;x1++)
                    for(y1=1;y1<y;y1++)
                        if (a[x1][y1]>k) k=a[x1][y1];
                a[x][y]=k+1;
                if (a[x][y]>kmax) {kmax=a[x][y]; x2=x; y2=y;}
            }
    printf("%d\n",kmax);
    k=kmax;
    do
    {
        v[k--]=v1[x2];
        if (k)
        {
            for(x1=x2-1;x1>=1;x1--)
            {
                for(y1=y2-1;y1>=1;y1--)
                    if (a[x1][y1]==k) break;
                if (a[x1][y1]==k) break;
            }
            x2=x1; y2=y1;
        }
    }while(k);

    for(x=1;x<=kmax;x++) printf("%d ",v[x]);
    printf("\n");
    return 0;
}
