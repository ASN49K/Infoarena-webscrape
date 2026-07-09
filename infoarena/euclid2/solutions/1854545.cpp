#include<stdio.h>
using namespace std;
int T, A, B;

int gcd(int a, int b){
    if(!b)return a;
    return gcd(b, a % b);
}

int main(){

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);


    for(scanf("%d", &T); T; --T){
        scanf("%d %d", &A, &A);
        printf("%d\n", gcd(A, B));
    }
    return 0;
}
