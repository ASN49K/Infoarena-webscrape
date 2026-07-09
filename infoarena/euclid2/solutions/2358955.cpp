#include <stdio.h>

int gcd(int a, int b){

    if (!b)
        return a;
    return gcd(b, a % b);}


int main(void){
    int NrPerechi, A, B;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &NrPerechi);

    while(NrPerechi){
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
        NrPerechi--;}

    return 0;}
