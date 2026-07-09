#include <cstdio>

using namespace std;

int main() {
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int k;
    scanf("%d",&k);
    for(int o=1; o<=k; o++) {
        int n,rez,x;
        scanf("%d%d",&n,&x);
        rez=x;
        for(int i=2; i<=n; i++) {
            scanf("%d",&x);
            rez=rez^x;
        }
        if(rez==0) {
            printf("NU\n");
        }else{
            printf("DA\n");
        }
    }

    return 0;
}
