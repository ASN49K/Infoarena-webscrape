#include <stdio.h>

using namespace std;
int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    freopen("cmmdc.in","r",stdin);
    freopen("cmmdc.out","w",stdout);
    int n,a,b;
    scanf("%d%d",&a,&b);
    n=cmmdc(a,b);
    if(n>1)printf("%d",n);
    else printf("0");
    return 0;
}
