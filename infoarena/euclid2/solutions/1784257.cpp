#include <iostream>
#include <cstdio>

using namespace std;

int cmd(int a, int b){
    if (!b) return a;
    else return cmd(b, a%b);
}

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    int t, a, b;
    scanf("%d", &t);
    for(; t; --t){
        scanf("%d %d", &a, &b);
        printf("%d\n", cmd(a,b));
    }
    return 0;
}
