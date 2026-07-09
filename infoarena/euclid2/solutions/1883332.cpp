#include <cstdio>
using namespace std;

int gcd(int a, int b){
    return (b) ? gcd(b, a % b) : a;
}

int main(){

int T, a, b;

freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);

scanf("%d", &T);

while(T--){
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}
return 0;
}
