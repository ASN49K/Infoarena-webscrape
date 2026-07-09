#include <cstdio>
using namespace std;
int euclid(int a,int b)
{
    if(b==0)
        return a;
    else return euclid(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,i,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
