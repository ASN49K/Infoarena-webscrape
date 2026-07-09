#include<cstdio>
using namespace std;

int main(){
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        int n,nr,s=0;
        scanf("%d", &n);
        for(int j=1;j<=n;j++){
            scanf("%d", &nr);
            s=s^nr;
        }
        if(s==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
