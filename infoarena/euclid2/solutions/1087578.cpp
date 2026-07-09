#include <cstdio>

using namespace std;
int euclid(int a,int b)
{
    if(!b)return a;
    return euclid(b,a%b);
}
int n,x,y;
int main()
{
    int i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        printf("%d\n",euclid(x,y));
    }
    return 0;
}
