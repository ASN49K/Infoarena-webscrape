#include <cstdio>
#define xorsum(a,b) ((a^=b))
using namespace std;

int main()
{
    int t;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    for(;t;--t){
        int n,sum=0,x,ok=1;
        scanf("%d",&n);
        for(int i=1;i<=n;scanf("%d",&x),(xorsum(sum,x)!=0)?0:ok=0,++i);
        if(!ok)printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
