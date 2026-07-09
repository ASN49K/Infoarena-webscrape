#include <cstdio>
int n,t,x,r;

int main(){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        r = 0;
        while(n--)
        {
            scanf("%d",&x);
            r ^= x;
        }
        if(r==0)printf("NU\n"); else printf("DA\n");
    }
    return 0;
}
