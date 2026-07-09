#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cmmdc(int a,int b)
{
    if(!b) return a;
    else return cmmdc(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int i,t,a,b;
    scanf("%i", &t);
    for(i=0;i<t;i++)
    {
                    scanf("%i %i", &a,&b);
                    printf("%i\n", cmmdc(a,b));
    }
    scanf("%i", &i);
    return 0;
}
