#include <stdio.h>

#define MAX(x,y) (x)>(y)?(x):(y)
int sol[1025][1025] = {0};
int am[1024], an[1024];
int m = 0, n = 0;

int main() {
    FILE *f = fopen("cmlsc.in", "r");
    FILE *out = fopen("cmlsc.out", "w+");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);

    for (int i = 0; i < m; i++) fscanf(f, "%d", &am[i]);
    for (int i = 0; i < n; i++) fscanf(f, "%d", &an[i]);
    fclose(f);
    
    for (int i = 1; i < m+1; i++) for (int j = 1; j < n+1; j++) {
            sol[i][j] += MAX(sol[i-1][j],sol[i][j-1]);
            if (am[i-1] == an[j-1]) sol[i][j] += 1;
        };
    fprintf(out, "%d\n", sol[m][n]);

    int i = 0, j = 0;
    while (i < m+1 && j < n+1) {
        if (MAX(sol[i][j+1], sol[i+1][j]) < sol[i+1][j+1]) {
            fprintf(out, "%d ", an[j]);
            ++j;
        };
        ++i;
    };
    fclose(out);
    return 0;
};