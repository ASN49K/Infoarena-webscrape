#include<cstdio>
using namespace std;
int i, t, a, b, c;
int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &t);
    for (i=1;i<=t;i++) {
        scanf("%d%d", &a, &b); c=0;
        if (a<b) {a=a+b; b=a-b; a=a-b;}
        while (a%b!=0) {
            c=a%b; a=b; b=c;
        }
        printf("%d\n", b);
    }
    return 0;
}
