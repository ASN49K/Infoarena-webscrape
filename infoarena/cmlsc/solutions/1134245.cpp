#include <cstdio>

const int Q=1024;

int a,b;
int v[Q+1],t[Q+1];

int prc[Q+1][Q+1];

int max(int a, int b)
{
    return a>b?a:b;
}

int beck(int n, int m)
{
    if(m==0 || n==0)
        return 0;

    if(prc[n][m]!=0)
        return prc[n][m];

    if(v[n]==t[m])
    {
        prc[n][m]=1+beck(n-1,m-1);
        return prc[n][m];
    }
    prc[n][m]=max(beck(n-1,m),beck(n,m-1));
    return prc[n][m];
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&a,&b);

    for(int i=1; i<=a; i++)
        scanf("%d",&v[i]);

    for(int j=1; j<=b; j++)
        scanf("%d",&t[j]);

    printf("%d",beck(a,b));


    return 0;
}
