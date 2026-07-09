#include<cstdio>
int main(){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int mask=0;
        scanf("%d",&n);
        while(n--){
            int x;
            scanf("%d",&x);
            mask^=x;
        }
        if(mask)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
