#include <stdio.h>

#undef BUFSIZ
#define BUFSIZ 1024



int main()
{
    FILE *input = fopen("cmlsc.in", "r");
    FILE *output = fopen("cmlsc.out", "w");

    int M, N, i, j, poz = 0, k = 0, count;
    int a[BUFSIZ], b[BUFSIZ], c[BUFSIZ];

    fscanf(input, "%d%d", &M, &N);

    for (i = 0; i < M; fscanf(input, "%d ", &a[i]), i++);
    for (i = 0; i < N; fscanf(input, "%d", &b[i]), i++);


    for (i = 0; i < M; i++)
        for (j = poz; j < N; j++) {
            if (a[i] == b[j]) {
                poz = j;
                c[k] = a[i];
                k++; j = N-1;
            }

        }
    fprintf(output, "%d\n", k);
    for (count = 0; count < k;  fprintf(output, "%d ", c[count]), count++);

    fclose(input);
    fclose(output);

}
