#include <cstdio>

int main(){
    int x,n,s,t;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
        scanf("%d",&t);
        while(t--){
            x=0;
            scanf("%d",&n);
            while(n--)
                scanf("%d",&s),x^=s;
            if(x==0)printf("NU\n"); else printf("DA\n");
        }
}
