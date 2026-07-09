//Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.

#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }

    return 0;
}
