#include<stdio.h>
long x,y,l,r,n;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&n);
    do
    {
                   l++;
                   scanf("%ld%ld",&x,&y);
                   r=x%y;
                   while(r!=0)
                   {
                              x=y;
                              y=r;
                              r=x%y;
                   }
                   printf("%ld\n",y);
    }
    while(l<n);
    return 0;
}
