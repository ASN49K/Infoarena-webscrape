#include <cstdio>
#include <algorithm>

using namespace std;

#define DIM 1025

FILE *fin = fopen("cmlsc.in","r");
FILE *fout = fopen("cmlsc.out","w");

int n, m, i, j, bst, sir[DIM], d[DIM][DIM], a[DIM], b[DIM];

int main() {
    fscanf(fin, "%d %d", &n, &m);

    for(i = 1;i <= n;i++) {
        fscanf(fin, "%d", &a[i]);
    }

    for(i = 1;i <= m;i++) {
        fscanf(fin, "%d", &b[i]);
    }

    for(i = 1;i <= n;i++) {
        for(j = 1;j <= m;j++) {
            if(a[i] == b[j]) {
                d[i][j] = 1 + d[i - 1][j - 1];
            }
            else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    for(i = n, j = m;i;) {
        if(a[i] == b[j]) {
            sir[++bst] = a[i];
            i--;
            j--;
        }
        else if(d[i - 1][j] < d[i][j - 1]) {
                j--;
             }
             else i--;

        if(i < 1) break;
        if(j < 1) break;
    }

    fprintf(fout, "%d\n", bst);

    for(i = bst;i >= 1;i--) {
        fprintf(fout, "%d ", sir[i]);
    }

    fprintf(fout, "\n");

    fclose(fin);
    fclose(fout);

    return 0;
}
