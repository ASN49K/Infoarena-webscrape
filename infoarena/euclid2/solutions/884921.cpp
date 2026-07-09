#include<stdio.h>
int a,b,c,d,r,x,t;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    x=1;
    while(x<=t)
    {
        scanf("%d %d",&a,&b);
        c=a;
        d=b;
        while(d!=0)
        {
            r=c%d;
            c=d;
            d=r;
        }
        printf("%d",c);
        printf("\n");
        x=x+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
