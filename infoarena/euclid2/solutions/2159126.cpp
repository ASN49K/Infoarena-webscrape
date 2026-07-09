#include <iostream>
#include <cstdio>
using namespace std;
int a,b;
int cmmdc()
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    if(a==1)
        return 0;
    return a;
}
int main()
{
    freopen("cmmdc.in","r",stdin);
    freopen("cmmdc.out","w",stdout);
    scanf("%d\n%d",&a,&b);
    int best=cmmdc();
    printf("%d\n",best);
    return 0;
}
