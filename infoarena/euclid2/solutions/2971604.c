#include <stdio.h>
#include <stdlib.h>
unsigned int Euclid(unsigned int a,unsigned int b)
{
    unsigned int r=0;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;

}
int main()
{
    freopen("euclid2.in","w",stdin);
    freopen("euclid2.out","r",stdout);


     unsigned int T=0,a,b;
     scanf("%u",&T);
     while(T>0)
     {
         scanf("%u %u",&a,&b);
         printf("%u\n",Euclid(a,b));
     }
    return 0;
}
