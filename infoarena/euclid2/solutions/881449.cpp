#include<cstdio>
long cmmdc(long a,long b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T;
    long a,b;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",cmmdc(a,b));
        }
    return 0;
}
