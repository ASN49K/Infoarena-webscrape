#include <stdio.h>

long gdc(long num1, long num2) {
    if (num2 == 0) 
        return num1;
    return gdc(num2, num2 % num1);
}

int main() {
    FILE *file = fopen("euclid2.in", "rt");
    FILE *file2 = fopen("euclid2.out", "wt");
    int n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; ++i) {
        long num1, num2;
        fscanf(file, "%ld%ld", &num1, &num2);
        fprintf(file2, "%ld\n", gdc(num1, num2));
    }
    fclose(file);
    fclose(file2);
    return 0;
}