#include <stdio.h>

long Euclid2(long a, long b)
{
    int temp;
    while (b)
    {
        temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}

int main()
{
    int T, a, b;

    FILE *input = fopen("euclid2.in", "r");
    FILE *output = fopen("euclid2.out", "w");

    for (fscanf(input, "%d", &T); T; --T)
    {
        fscanf(input, "%d%d", &a, &b);
        fprintf(output, "%d\n", Euclid2(a, b));
    }

    fclose(input);
    fclose(output);


}
