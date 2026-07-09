#include <cstdio>

using namespace std;
int cmmdc(int a,int b)
{
    while(a) {
        b = b % a;
        a = a + b - (b = a);
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,a1,a2;
    scanf("%d",&t);
    for(int i =1;i<=t;i++)
    {
        scanf("%d%d",&a1,&a2);
        printf("%d\n",cmmdc(a1,a2));
    }
    return 0;
}
