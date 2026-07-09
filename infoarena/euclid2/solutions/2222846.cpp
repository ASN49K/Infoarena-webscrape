#include <stdio.h>
int t,a,b;
int eu(int a,int b)
{
    if(!b)return a;
    return eu(b,a%b);
}
int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",eu(a,b));
    }
    return 0;
}
