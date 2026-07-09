#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int cmmdc(int a, int b){
    if(!b)
        return a;
    else
        return cmmdc(b, a % b);
}

int main()
{
    FILE *input, *output;

    input = fopen("euclid2.in", "r");
    output = fopen("euclid2.out", "w");

    int a[100000];
    int n, i;

    fscanf(input, "%d", &n);

    for(i = 0; i < 2 * n; i++)
        fscanf(input, "%d", &a[i]);

    for(i = 0; i < 2 * n - 1; i += 2){
        fprintf(output, "%d\n", cmmdc(a[i], a[i+1]));
    }

    return 0;
}
