#include <stdio.h>

int euclid (int a, int b)
{
    if (!(a%b))
        return b;
    else
        return euclid (b,a%b);
}

int main()
{
    int a,b,t,i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
