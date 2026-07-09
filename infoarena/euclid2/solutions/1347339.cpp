#include <iostream>
#include <fstream>

using namespace std;

int n,a,b;

int gcd(int  a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int i;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}
