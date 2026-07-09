#include <stdio.h>

int main () {

int n, a, b;
freopen("euclid2.in","r", stdin);
freopen("euclid2.out","w", stdout);
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    printf("%d\n", a);
}
fclose(stdin);
fclose(stdout);
}