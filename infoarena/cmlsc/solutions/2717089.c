#include <stdio.h>

#define MAX(x,y) (x)>(y)?(x):(y)

int sol[1025][1025] = {0};
int rez[1024] = {0};
int am[1024], an[1024];
int m = 0, n = 0, p = 0;

int main() {
    FILE *f = fopen("cmlsc.in", "r");
    FILE *out = fopen("cmlsc.out", "w");
    fscanf(f, "%d", &m);
    fscanf(f, "%d", &n);

    for (int i = 0; i < m; i++) fscanf(f, "%d", &am[i]);
    for (int i = 0; i < n; i++) fscanf(f, "%d", &an[i]);
    fclose(f);
    
    for (int i = 1; i < m+1; i++) for (int j = 1; j < n+1; j++) 
        if (am[i-1] == an[j-1]) sol[i][j] = sol[i-1][j-1] + 1; else sol[i][j] += MAX(sol[i-1][j],sol[i][j-1]);

    fprintf(out, "%d\n", sol[m][n]);


    while (m > 0 && n > 0) {
        if (am[m-1] == an[n-1]) rez[p++] = am[m-1];
        if (sol[m-1][n] == sol[m][n-1]) {
            m--;
            n--;
        } else {
            if (sol[m-1][n] < sol[m][n-1]) n--;
            if (sol[m-1][n] > sol[m][n-1]) m--;
        };
    };
    for (int i = p - 1; i >= 0; i--) {
        fprintf(out, "%d ", rez[i]);
    };
    fclose(out);
    return 0;
};