#include<cstdio>
using namespace std;
int euclid(int a,int b)
{
    if(!b)
        return a;
    return euclid(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);
    int t,a,b;
    scanf("%d",&t);
    for(;t;--t)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
}
