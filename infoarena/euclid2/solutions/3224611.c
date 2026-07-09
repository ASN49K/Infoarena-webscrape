#include <stdio.h>

int main () {

int n, a, b;
freopen("euclid2.in","r", stdin);
freopen("euclid2.out","w", stdout);
scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    while (a != b) {
        if (a > b) 
            a = a - b;
        else 
            b = b - a;
    }
    printf("%d\n", a);
}
fclose(stdin);
fclose(stdout);
}