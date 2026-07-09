#include <stdio.h>
long t,a,b,i;
int dc(int a, int b)   
{   
    if (!b) return a;   
    return dc(b, a % b);   
}   

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdin);
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
       {
       scanf("%ld %ld\n",&a,&b);
       printf("%ld",dc(a,b));
       }
    return 0;
}
