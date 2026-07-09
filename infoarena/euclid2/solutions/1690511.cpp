#include <cstdio>
int a, b, t;
int GCD(int a, int b){
    if(!b) return a;
    else return GCD(b, a%b);
}
int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", GCD(a, b));
    }
    return 0;
}
