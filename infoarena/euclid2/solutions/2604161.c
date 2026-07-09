#include <stdio.h>
#include <stdlib.h>

int euclid(int a, int b) {

    int r;

    while(b != 0) {

        r = a % b;
        a = b;
        b = r;

    }

    return a;

}

int main()
{
    FILE* in = fopen("euclid2.in", "r");

    int t, a ,b;
    fscanf(in, "%d", &t);

    for(int i = 0; i < t; i++) {

        fscanf(in, "%d %d", &a, &b);
        printf("%d\n", euclid(a, b));

    }
    return 0;
}
