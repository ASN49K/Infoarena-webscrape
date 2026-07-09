#include<stdio.h>
using namespace std;
int a,b,r,i,n;
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&a);
    scanf("%d",&b);
    r=0;
    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    printf("%d\n",a);
}
return 0;
}
