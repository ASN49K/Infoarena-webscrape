#include<cstdio>
using namespace std;
int main (){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,i,n,q,xor_sum,x;
    scanf("%d",&t);
    for(q=1;q<=t;q++){
        scanf("%d",&n);
        xor_sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            xor_sum^=x;
        }
        if(xor_sum>0)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
