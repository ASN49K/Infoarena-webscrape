#include<stdio.h>
#define input "euclid2.in"
#define output "euclid2.out"
#define dim 101
int n,a,b,r;
int main()
{
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%d%d",&a,&b);
                     while(a%b)
                     {
                             r=a%b;
                             a=b;
                             b=r;
                     }
    printf("%d\n",b);
    }
return 0;
} 
    
