#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *r, *w;
    r = fopen("euclid2.in", "r");
    w = fopen("euclid2.out", "w");

    int n, i, a, b, x;
    fscanf(r, "%d", &n);
    for(i = 1; i <= n; i++){
        fscanf(r, "%d%d", &a, &b);
        while(a){
            x = b%a;
            b = a;
            a = x;

        }
        fprintf(w, "%d\n", b);
    }

    return 0;
}
