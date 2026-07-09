#include<cstdio>
using namespace std;
int cmmdc(int a,int b)
{
    while(b)
    {
        int rest=a%b;
        a=b;
        b=rest;
    }
    return a;
}
int main()
{
    int n,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }

}
