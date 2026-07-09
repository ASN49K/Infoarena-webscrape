#include <stdio.h>
#include <stdlib.h>

void swap (double *a, double *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    FILE *input, *output;

    input = fopen("euclid2.in", "r");
    output = fopen("euclid2.out", "w");

    double a[100000];
    int n, i;

    fscanf(input, "%d", &n);

    for(i = 0; i < 2 * n; i++)
        fscanf(input, "%lf", &a[i]);

    for(i = 0; i < 2 * n - 1; i += 2){
        while(a[i] > 0 && a[i+1] > 0 && a[i] != a[i+1]){
            if(a[i] > a[i+1])
                a[i] -= a[i+1];
            else
                if(a[i] < a[i+1]){
                    swap(&a[i], &a[i+1]);
                    a[i] -= a[i+1];
                }
        }
        fprintf(output, "%lf\n", a[i]);
    }

    return 0;
}
