#include<cstdio>
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T;
    long a,b;
    int r;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
        {
            scanf("%d%d",&a,&b);
                while(b)
                {
                r=a%b;
                a=b;
                b=r;
                }
            printf("%d\n",a);
        }
    return 0;
}
