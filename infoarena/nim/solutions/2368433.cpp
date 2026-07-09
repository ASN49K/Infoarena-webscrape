#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,XoR=0;
        scanf("%d",&n);
        while(n--){
            int x;
            scanf("%d",&x);
            XoR^=x;
        }
        if(XoR==0)
            printf("NU\n");
        else printf("DA\n");
    }
    return 0;
}
