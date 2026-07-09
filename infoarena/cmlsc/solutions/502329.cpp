#include <stdio.h>

int a[1025],b[1025],d[1025][1025],s[1025],m,n,i,j,sol;

inline int max(int x,int y)
{
    if (x>y) return x;
    return y;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<=m;++i) scanf("%d",&b[i]);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    i=n;j=m;
    while (i&&j)
    {
        if (a[i]==b[j])
        {
            ++sol;
            s[sol]=a[i];
            --i;
            --j;
        }
        else if (d[i-1][j]<d[i][j-1]) --j;
        else --i;
    }
    printf("%d\n",sol);
    for (i=sol;i>0;--i) printf("%d ",s[i]);
    return 0;
}
