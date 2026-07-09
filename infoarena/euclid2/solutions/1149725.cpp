#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, a, b, rez;

int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d\n", &t);
    for(int i=0; i<t; i++){
        scanf("%d %d\n", &a, &b);
        rez = cmmdc(a, b);
        printf("%d\n", rez);
    }

    return 0;
}
