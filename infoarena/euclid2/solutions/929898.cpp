#include<cstdio>
 
unsigned int a,b,r;
int t;
 
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<t;++i)
    {
        scanf("%d%d",&a,&b);
        r=a%b;
        while(r>0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        printf("%d\n",b);
    }
    return 0;
}