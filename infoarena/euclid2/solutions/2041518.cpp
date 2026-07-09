#include <stdio.h>
#include <stdlib.h>
using namespace std;


int n;

struct per{
    int a, b;
}pereche;

int rezolvare(int a,int b){
    if(!b) return a;
    else rezolvare(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &pereche.a, &pereche.b);
        printf("%d\n", rezolvare(pereche.a, pereche.b));
    }
    return 0;
}
