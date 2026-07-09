#include <stdio.h>

int Euclid2(int a, int b)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0)
    {
        a = a % b;
        b = b-a;
    }

    return b;
}

int main()
{
    int k, a, b;
    int i;
    FILE *input = fopen("euclid2.in", "r");
    FILE *output = fopen("euclid2.out", "w");

    fscanf(input, "%d", &k);

    for (i = 1; i <= k; i++)
    {
        fscanf(input, "%d%d", &a, &b);
        fprintf(output, "%d\n", Euclid2(a, b));
    }

    fclose(input);
    fclose(output);


}
