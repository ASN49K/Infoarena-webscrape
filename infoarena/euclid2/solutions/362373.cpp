#include <iostream.h>
#include <stdio.h>
 
using namespace std;
unsigned i,t,r,a,b;
 
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%u",&t);
    for(i=1;i<=t;i++)		
    {
        scanf("%u%u",&a,&b);
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
            printf("%u\n",a);
    }
}