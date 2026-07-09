#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,n,x,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
        for(register int i=1;i<=n;i++){
            scanf("%d",&x);
            sum^=x;
        }
        if(sum==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
