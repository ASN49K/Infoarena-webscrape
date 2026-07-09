#include <stdio.h>

using namespace std;
int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
    }
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int m,n,t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++){
        scanf("%d %d", &m, &n);
        printf("%d\n", gcd(m,n));
        }
    return 0;
}
