#include <cstdio>
using namespace std;
int t,i,a,b;
void rezolva(int a, int b)
{
    int d,r;
    if (a<b) {d=a;a=b;b=d;}
    while (a!=b)
    {
        r=a-b;
        if (b>r){
        a=b;b=r;} else {a=r;}
    }
    printf("%d\n",a);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        rezolva(a,b);
    }
    return 0;
}
