#include <iostream>
#include <stdio.h>
using namespace std;


int GCD(int a, int b){

    if(!b) return a;
    return GCD(b, a % b);

}
int main()
{
    int T, a,b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &T);

    for(; T; --T)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", GCD(a,b));
    }

    return 0;
}
