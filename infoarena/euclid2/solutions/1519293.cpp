#include <stdio.h>

using namespace std;

int cmmdc(int a, int b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a=a%b;
        else b=b%a;
    }
    return a+b;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a,b,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
