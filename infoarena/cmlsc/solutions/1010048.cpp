#include <stdio.h>

#define maxx(a,b) ((a>b)?a:b)
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define mnx 1024

int n,m,a[mnx],b[mnx],d[mnx][mnx],er[mnx],h;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    fr(i,1,m)
        scanf("%d",&a[i]);
    fr(i,1,n)
        scanf("%d",&b[i]);

    fr(i,1,m)
        fr(j,1,n)
            if(a[i]==b[j])
                    d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxx(d[i-1][j],d[i][j-1]);

    int i=m;int j=n;
    while(i>0)
        if(a[i]==b[j])
        {
            er[++h]=a[i];
            --i;--j;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                --j;
            else --i;
        }

    printf("%d\n", h);
    for (int i = h; i>0; --i)
        printf("%d ", er[i]);

    return 0;
}
