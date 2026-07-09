#include <stdio.h>
#include <stdlib.h>
const int MAXSIZE=100000;

int euclid(int a,int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    int T,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    for(;T;T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    return 0;
}
