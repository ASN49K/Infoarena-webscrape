#include<cstdio>
using namespace std;

int gcd(int a, int b) {

    while(a) {
        b = b % a;
        a = a + b - (b = a);
    }
    return a;
}

int main() {

    int t = 0, a = 0, b = 0;

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d",&t);

    for (int i = 1; i <= t; ++i) {
        scanf("%d",&a,&b);
        printf("%d\n",gcd(a,b));
    }

    return 0;
}
