#include<stdio.h>
using namespace std;
int T, A, B;

int gcd(int a, int b){
    if(!b)return a;
    return gcd(b, a % b);
}

int main(){

    freopen("cmmdc.in", "r", stdin);
    freopen("cmmdc.out", "w", stdout);

    scanf("%d", &T);
    for(; T; --T){
        scanf("%d %d", &A, &A);
        printf("%d\n", gcd(A, B));
    }
    return 0;
}
