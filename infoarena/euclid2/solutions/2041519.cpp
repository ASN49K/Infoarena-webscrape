#include <stdio.h>
#include <stdlib.h>
using namespace std;
int rezolvare(int a,int b){
    if(!b) return a;
    else rezolvare(b, a%b);
}
int main()
{
    int n, a, b;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", rezolvare(a, b));
    }
    return 0;
}
