#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024

int a[MAXN], b[MAXN];
int d[MAXN + 1][MAXN + 1];
int v[MAXN];

int max(int x, int y){
    return x > y ? x : y;
}

int main()
{
    FILE *fin, *fout;
    fin = fopen("cmlsc.in", "r");
    fout = fopen("cmlsc.out", "w");

    int n, m, i, j, lmax;

    fscanf(fin, "%d%d", &n, &m);

    for(i = 0; i < n; i++){
        fscanf(fin, "%d", &a[i]);
    }
    for(i = 0; i < m; i++){
        fscanf(fin, "%d", &b[i]);
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    lmax = d[n][m];

    fprintf(fout, "%d\n", lmax);

    i = n;
    j = m;
    while(lmax){
        if(d[i - 1][j] == lmax){
            i--;
        }
        else if(d[i][j - 1] == lmax){
            j--;
        }
        else{
            i--;
            j--;
            lmax--;
            v[lmax] = a[i];
        }
    }

    for(i = 0; i < d[n][m]; i++){
        fprintf(fout, "%d ", v[i]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
