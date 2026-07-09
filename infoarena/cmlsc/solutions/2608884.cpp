#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

void findLongestCommonSequence(int *first, int *second, int n, int m) {
    int **lengths;

    lengths = (int **)calloc( (n + 1), sizeof(int *));
    for (int i = 0; i < n + 1; i++) {
        lengths[i] = (int *)calloc( (m + 1), sizeof(int));
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j++) {
            lengths[i][j] = max3(lengths[i - 1][j], lengths[i][j - 1], lengths[i - 1][j - 1]) + ((first[i - 1] == second[j - 1]) ? 1 : 0);
        }
    }


    int length = lengths[n][m];
    int *result = (int *)calloc(length, sizeof(int));
    int index = 0;

    int row = n;
    int column = m;


    while (row != 0 && column != 0) {
        if (first[row - 1] == second[column - 1]) {
            result[index] = first[row - 1];
            index++;
            row--;
            column--;
        } else if (lengths[row][column - 1] > lengths[row - 1][column]) {
            column--;
        } else {
            row--;
        }
    }

    FILE *g = fopen("cmlsc.out", "w");

    fprintf(g, "%d\n", length);
    for (int i = length - 1; i >= 0; i--) {
        fprintf(g, "%d ", result[i]);
    }

    fclose(g);
}

int main() {
    int n, m;
    int *first, *second;

    FILE *f = fopen("cmlsc.in", "r");
    fscanf(f, "%d %d", &n, &m);

    first = (int *)calloc(n, sizeof(int));
    second = (int *)calloc(m, sizeof(int));

    for (int i = 0; i < n; i++) {
        int tmp;
        fscanf(f, "%d", &tmp);
        first[i] = tmp;
    }

    for (int i = 0; i < m; i++) {
        int tmp;
        fscanf(f, "%d", &tmp);
        second[i] = tmp;
    }

    findLongestCommonSequence(first, second, n, m);

    fclose(f);

    return 0;
}