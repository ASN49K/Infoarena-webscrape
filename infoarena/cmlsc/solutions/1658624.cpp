#include <iostream>
#include <cstdio>
using namespace std;

const int nmax=1025;

short a[nmax][nmax],v1[nmax],v2[nmax],v[nmax],n1,n2,x,y,x1,y1,k,kmax;

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

int maxim(int i, int j)
{
    if (i>j) return i;
    else return j;
}

int main()
{
    citire();

    for(x=1;x<=n1;x++)
        for(y=1;y<=n2;y++)
        {
            if(v1[x]==v2[y])
            {
                a[x][y]=a[x-1][y-1]+1;
                //if (a[x][y]>kmax) kmax=a[x][y];
            }
            else a[x][y]=maxim(a[x-1][y],a[x][y-1]);
        }
    /*printf("%d\n",kmax);
    k=kmax;

    x=n1; y=n2;
    do
    {
        if (v1[x]==v2[y])
            v[k--]=v1[x], --x, --y;
        else if (a[x-1][y]<a[x][y-1])
            --y;
        else
            --x;
    }while(k);*/

    k=0;
    for (x = n1, y = n2; x; )
        if (v1[x]==v2[y])
            v[++k]=v1[x], --x, --y;
        else if (a[x-1][y]<a[x][y-1])
            --y;
        else
            --x;

    printf("%d\n",k);
    for (x = k; x; --x)
        printf("%d ", v[x]);
    //for(x=1;x<=kmax;x++) printf("%d ",v[x]);
    printf("\n");
    return 0;
}
