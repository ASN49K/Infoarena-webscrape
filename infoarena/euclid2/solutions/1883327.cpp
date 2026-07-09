#include <cstdio>
using namespace std;

int gcd(int a, int b){
    return (b) ? gcd(b, a % b) : 0;
}

int main(){

int T, a, b;

freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);

fscanf(file1, "%d", &T);

while(T--){
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}
return 0;
}
