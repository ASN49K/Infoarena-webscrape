#include<cstdio>

#define MAX 1025

inline int max(int a,int b)
{
    if (a>b) return a;
    else return b;
};

int a[MAX];
int b[MAX];
int d[MAX][MAX];
int n,m;
int cmlsc[MAX],cntCmlsc = 0;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);

    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int j=1;j<=m;++j)
        scanf("%d",&b[j]);

    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1] +1;
            else d[i][j] = max(d[i-1][j],d[i][j-1]);

    int i = n,j = m;

    while (i)
    {
        if (a[i] == b[j])
            cmlsc[++cntCmlsc] = a[i],--i,--j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else --i;
    }

    printf("%d\n",cntCmlsc);
    for (int i=cntCmlsc;i;--i)
        printf("%d ",cmlsc[i]);

    return 0;
}
