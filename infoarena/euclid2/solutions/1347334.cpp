#include <iostream>
#include <fstream>

using namespace std;

long long n,a,b;

long long gcd(long long  a, long long b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    long long i;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d %d", &a, &b);
        printf("%d %d", a, b);
    }

    return 0;
}
