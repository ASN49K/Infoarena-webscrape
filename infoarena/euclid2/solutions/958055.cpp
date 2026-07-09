#include <iostream>
#include <stdio.h>
using namespace std;


int GCD(int a, int b){

    if(!b) return a;

    if(a > b) return GCD(a-b,a);
    else return GCD(a, b-a);

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
