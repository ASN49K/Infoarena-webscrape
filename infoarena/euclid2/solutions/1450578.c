#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
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

    int a[100000];
    int n, i;

    fscanf(input, "%d", &n);

    for(i = 0; i < 2 * n; i++)
        fscanf(input, "%d", &a[i]);

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
        fprintf(output, "%d\n", a[i]);
    }

    return 0;
}
