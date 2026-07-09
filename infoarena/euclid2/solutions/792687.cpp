#include <cstdio>

int N;

int gcd(int a,int b) {
    int c;
    while (b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main () {

    int a,b;

    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);

    scanf("%d",&N);
    for (int line=0; line<N; ++line) {
        scanf("%d %d", &a, &b);
        printf("%d\n",gcd(a,b));
    }

    return 0;
}
