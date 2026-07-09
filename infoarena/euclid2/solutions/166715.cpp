#include <stdio.h>
int t,a,b,i;
int dc(int a, int b)   
{   
    if (!b) return a;   
    return dc(b, a % b);   
}   

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
       {
       scanf("%d %d",&a,&b);
       printf("%d\n",dc(a,b));
       }
    return 0;
}
