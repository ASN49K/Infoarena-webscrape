#include<cstdio>
int n,i;
long long a,b;

long long euclid(long a,long b)
{
    int r=a%b;
    while(r)a=b,b=r,r=a%b;
    return b;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",euclid(a,b));
    }
    return 0;
}
