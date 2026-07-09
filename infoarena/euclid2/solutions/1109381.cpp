#include <fstream>
#include <stdio.h>
using namespace std;
int x[100],n;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
