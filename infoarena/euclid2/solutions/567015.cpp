#include <iostream>
#include <stdio.h>

using namespace std;

int t,nr,n,a,b,i;

int cmmdc(int a, int b)
{
    int r;

    if (a<b)
    {
        r=a;a=b;b=r;r=0;
    }
    while (b!=0)
    {
        r=a%b;
        a=b;b=r;
    }
    return a;
}

int main()
{

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }


    return 0;
}
