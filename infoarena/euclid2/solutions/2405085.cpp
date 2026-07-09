#include <stdio.h>
int gcd(int a, int b);

int main(){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n; 

    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        int a; int b;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    gcd(b, a%b);
}