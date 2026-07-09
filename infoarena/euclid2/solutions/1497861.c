#include <stdio.h>
#include <stdlib.h>

int AlgoritmEuclid(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return AlgoritmEuclid(b,a%b);
}

int main()
{
    int t,i,a,b;

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",AlgoritmEuclid(a,b));
    }

    return 0;
}
