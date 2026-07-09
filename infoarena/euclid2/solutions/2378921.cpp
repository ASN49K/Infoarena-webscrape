#include <bits/stdc++.h>
using namespace std;
int Euclid(int a, int b){
    int r = a % b;
    while(r){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main(){
    int n;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        long long a, b;
        scanf("%lld%lld", &a, &b);
        printf("%d\n", Euclid(a, b));
    }
}
