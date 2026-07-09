#include<stdio.h>
int i,n,a,b;
int euclid(int a, int b)
{
    while(b)
    {

        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {

        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
