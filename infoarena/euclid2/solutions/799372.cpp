#include<cstdio>
void cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    printf("%d\n",a);
}
int main()
{
    int n,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d\n",&n);
    for(;n;n--)
    {
        scanf("%d%d",&a,&b);
        cmmdc(a,b);
    }
    return 0;
}
