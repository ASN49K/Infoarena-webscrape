#include <bits/stdc++.h>
using namespace std;

int cmmdc(int a, int b){
    if(b == 0) return a;
    return cmmdc(b, a % b);
}

int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for(; t > 0 ; t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
    return 0;
}
