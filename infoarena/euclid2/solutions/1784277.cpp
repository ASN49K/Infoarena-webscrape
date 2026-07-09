#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int t, a, b, r;
    scanf("%d", &t);
    for(; t; --t){
        scanf("%d %d", &a, &b);
        do{
            r=a%b;
            a=b;
            b=r;
        } while(r);
        printf("%d\n", a);
    }
    return 0;
}
